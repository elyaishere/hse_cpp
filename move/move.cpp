#include <iostream>
#include <utility>

struct String {
    String() = default;

    String(const String &) {
        puts("copy");
    }

    String(String &&) {
        puts("move");
    }
};

void eat(String) {}

void foo(const String&) {
    std::cout << "const String&\n";
}

void foo(String&&) {
    std::cout << "String&&\n";
}

void pipeline(String&& value) {
    foo(value);
    foo(std::move(value));
}

int main() {
    String s1;
    eat(std::move(s1));

    const String s2;
    eat(std::move(s2));

    pipeline(String{});
}
