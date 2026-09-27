#include <iostream>

struct Empty {};

struct A {
    Empty f1;
    Empty f2;
};

struct B : Empty {
    char f1;
    Empty f2;
};

struct C : Empty {
    Empty f1;
    char f2;
};


// [[no_unique_address]]
// https://en.cppreference.com/cpp/language/attributes/no_unique_address

struct Empty1 {};
struct Empty2 {};

struct Better {
    char value;

    [[no_unique_address]] Empty1 e1;
    [[no_unique_address]] Empty2 e2;
};


int main() {
    printf("Size of A: %zu\n", sizeof(A));
    printf("Size of B: %zu\n", sizeof(B));
    printf("Size of C: %zu\n", sizeof(C));

    printf("Size of Better: %zu\n", sizeof(Better));

    return 0;
}