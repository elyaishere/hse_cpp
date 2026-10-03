#include <cstddef>
#include <iostream>

struct base {
    size_t use_count;
    size_t weak_count;

    virtual ~base() noexcept { }
    // stuff
};

template<typename T>
struct in_place: base {
    alignas(T) std::byte value[sizeof(T)];
};

template<typename T>
struct pointer: base {
    T* ptr;
};

// про weak

struct B {
    virtual void clear() {
        delete this;
    };

    ~B() {
        std::cout << "~B()" << std::endl;
    };

};

struct A: B {
    virtual void clear() {
        delete this;
    };

    ~A() {
        std::cout << "~A()" << std::endl;
    };
};

int main() {
    B * a = new A();
    a->clear();
}

