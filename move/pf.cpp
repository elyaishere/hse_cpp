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

void inspect(String&) {
    std::cout << "String&\n";
}

void inspect(const String&) {
    std::cout << "const String&\n";
}

void inspect(String&&) {
    std::cout << "String&&\n";
}

void inspect(const String&&) {
    std::cout << "const String&&\n";
}

template<class T>
void forward(T&& value) {
    inspect(value);
}

int main() {
    String a;
    const String b;

    forward(a);
    forward(b);
    forward(std::move(a));
    forward(std::move(b));
    forward(String{});

}
