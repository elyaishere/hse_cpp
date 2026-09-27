#include <iostream>
#include <utility>

struct Object {
    Object() {
        std::cout << "ctor" << std::endl;
    }

    Object(const Object&) {
        std::cout << "copy" << std::endl;
    }

    Object(Object&&) {
        std::cout << "move" << std::endl;
    }
};

Object Foo1() {
    return Object{};
}

Object Foo2() {
    // NRVO
    Object o;
    return o;
}

Object Foo3() {
    Object o;
    return std::move(o);
}

Object Foo4() {
    Object o;
    Object& omg = o;
    return omg;
}

Object Foo5() {
    Object o;
    Object& omg = o;
    return std::move(omg);
}

int main() {
    { Object ex1 = Foo1(); }
    std::cout << "-----" << std::endl;
    { Object ex2 = Foo2(); }
    std::cout << "-----" << std::endl;
    { Object ex3 = Foo3(); }
    std::cout << "-----" << std::endl;
    { Object ex4 = Foo4(); }
    std::cout << "-----" << std::endl;
    { Object ex5 = Foo5(); }
}
