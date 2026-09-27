#include <memory>
#include <type_traits>
#include <tuple>
#include <iostream>

template <typename T>
struct default_delete {
    void operator()(T* ptr) const {
	    static_assert(!std::is_void<T>::value, "can't delete pointer to incomplete type");
	    static_assert(sizeof(T), "can't delete pointer to incomplete type");
	    
        delete ptr;
    }
};

template <typename T>
struct default_delete<T[]> {
    void operator()(T* ptr) const {
	    static_assert(sizeof(T), "can't delete pointer to incomplete type");
	    
        delete [] ptr;
    }
};


template <typename T, typename D = default_delete<T>>
class unique_ptr {
public:
    explicit unique_ptr(T* p) noexcept
	    : ptr(p) { }

    unique_ptr(unique_ptr&&) = default;
    unique_ptr& operator=(unique_ptr&&) = default;

    ~unique_ptr() noexcept {
        if (ptr != nullptr) {
            deleter(ptr);
            ptr = nullptr;
        }
    }

    T& operator*() const;

private:
    T* ptr;
    D deleter;
};

template <typename T, typename D>
class unique_ptr<T[], D> {
public:
    explicit unique_ptr(T* p) noexcept
	    : ptr(p) { }

    unique_ptr(unique_ptr&&) noexcept = default;
    unique_ptr& operator=(unique_ptr&&) noexcept = default;

    ~unique_ptr() noexcept {
        if (ptr != nullptr) {
            deleter(ptr);
            ptr = nullptr;
        }
    }

    T& operator[](size_t) const;

private:
    T* ptr;
    D deleter;
};

int main() {
    std::unique_ptr<int> ptr;

    std::cout << sizeof(unique_ptr<int>) << std::endl;
}
