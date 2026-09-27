#include <memory>
#include <type_traits>
#include <tuple>
#include <iostream>

template <typename T>
struct control_block {
    T* ptr;
    size_t counter1, cnt2;
};

template <typename T>
class shared_ptr {
public:
    explicit shared_ptr(T* p)
        : ptr(p), counter(new size_t(1)) { }

    ~shared_ptr() noexcept {
        if (--(*counter) == 0) {
            delete counter;
            delete ptr;
        }
    }

    template<typename... Args>
	shared_ptr(Args&&... args)
	// : cb<T>(std::forward<Args>(args)...)
	{ }

    T& operator*() const;

private:
    T* ptr;
    size_t* counter;
};


int main() {
    std::shared_ptr<int> ptr;

    std::cout << sizeof(shared_ptr<int>) << std::endl;
}
