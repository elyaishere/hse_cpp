#include <iostream>
#include <memory>

struct Base {
    virtual ~Base() = default;
};

template <typename T>
struct Derived: Base {
    template <typename... Args>
    Derived(Args&&... args) : value(std::forward<Args>(args)...) {
    }

    T& Get() {
        return value;
    }

private:
    T value;
};

struct Any {
    Any () = default;

    template <typename T>
    Any(T&& t) : ptr(new Derived<std::decay_t<T>>(std::forward<T>(t))) {
    }

    template <typename T>
    T& Get() {
        return static_cast<Derived<std::decay_t<T>>*>(ptr.get())->Get();
    }
    
    std::unique_ptr<Base> ptr;
};

int main() {
    Any a = 1;
    a = std::string{"hello"};
    std::cout << a.Get<std::string>() << std::endl;
    return 0;
}