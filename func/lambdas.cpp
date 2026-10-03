#include <iostream>
#include <functional>

int main () {
    // https://cppinsights.io/
    static int value = 42;
    auto l1 = [] { value++; };
    auto l2 = [v = value] mutable { v++; };
    l1(); l2();

    std::cout << value << std::endl;

    auto l3 = l1;
    l3();
    std::cout << value << std::endl;

    [] (auto a, auto b) { std::cout << a + b << std::endl; } (1, 2.0);
    auto tlambda = []<typename T>(T a) { std::cout << a << std::endl; };
    tlambda(42);

    // recursive (?)
    // auto fact = [] (int n) {
    //     if (n <= 1) return 1;
    //     return n * fact(n - 1);
    // };

    
}
