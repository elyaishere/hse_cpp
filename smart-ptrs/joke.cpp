#include <iostream>
#include <utility>
#include <cstring>

template <typename T>
void print(T&& ptr) {
    void* buf[sizeof(ptr) / sizeof(void*)];
    memcpy(buf, &ptr, sizeof(ptr) / sizeof(void*));
    for (void* p : buf) {
        std::cout << p << ' ';
    }
    std::cout << std::endl;
}


struct A {
    void foo() {
        std::cout << 67 << std::endl;
    }

    int j { 42 };
};

struct B {
    void foo() {
        std::cout << j << std::endl;
    }

    int j { 0 };
};

int main() {
    void (A::*pa)() = &A::foo;
    std::cout << sizeof(pa) << std::endl;
    print(pa);

    void (B::*pb)() = &B::foo;
    print(pb);

    char arr[8];
    memcpy(arr, (void*)&pa, 8);
    memcpy((char*)&pa, (void*)&pb, 8);
    memcpy((char*)&pb, arr, 8);
    print(pa);

    (A{}.*pa)();
}
