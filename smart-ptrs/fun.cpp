#include <iostream>
#include <utility>
#include <cstring>

template <typename T>
void print(T&& ptr) {
    void* buf[sizeof(ptr) / sizeof(void*)];
    memcpy(buf, &ptr, sizeof(ptr));
    for (void* p : buf) {
        std::cout << p << ' ';
    }
    std::cout << std::endl;
}

struct S0 {
    int a {1};
};

struct S1 {
    int b {2};
    void foo() {
        std::cout << "S1: " << 1488 << std::endl;
    }
};


struct A: S0, S1 {
    void foo() {
        std::cout << "A: " << 67 << std::endl;
    }

    int j { 42 };
};

struct B {
    void foo() {
        std::cout << "B: " << j << std::endl;
    }

    int j { 0 };
};

int main() {
    // look at assembly
    void (A::*pa)() = &S1::foo;
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
    // https://discourse.llvm.org/t/get-an-8byte-pointer-to-member-function/88625
}
