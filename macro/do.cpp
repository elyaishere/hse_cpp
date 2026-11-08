#include <iostream>

#define DO_WORK(i)            \
do {                          \
    int j = i;                \
    while (j-- > 0)           \
    std::cout << "working\n"; \
} while(0)

int main() {
    if (true) DO_WORK(8);
    else {
        std::cout << "chill\n";
    }
}
