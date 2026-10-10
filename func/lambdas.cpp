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

    // recursive
    // http://pedromelendez.com/blog/2015/07/16/recursive-lambdas-in-c14/

    // https://godbolt.org/z/33e8hMohW
    std::function<int(int)> f = [&f] (int n) {
        if (n <= 1) return 1;
        return n * f(n - 1);
    };
    std::cout << f(5) << std::endl;


    // class function {
    //     Any f; // union { void* ; char[]}
    //     F* invoker;
    // };
}
