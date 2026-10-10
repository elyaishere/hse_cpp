#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-local-addr"
#include <cstring>
#include <iostream>

template <typename T>
T const& max(T const& a, T const& b) {
    return a > b ? a : b;
}

char const* max(char const* a, char const* b) {
    return std::strcmp(a, b) > 0 ? a : b;
}

template <typename T>
T const& max(T const& a, T const& b, T const& c) {
    return max(max(a, b), c);
}

int main() {
    auto m1 = max(1, 2, 3);
    std::cout << m1 << std::endl;
    char const * a = "a";
    char const * b = "b";
    char const * c = "c";
    auto m2 = max(a, b, c);
    std::cout << m2 << std::endl;
    return 0;
}

#pragma GCC diagnostic pop

