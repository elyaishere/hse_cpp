#include <iostream>
#include <ranges>

namespace library {
template<class T>
void run(T value) {
    process(value);
}
}

namespace user {
struct Task {};

void process(Task) {
    std::cout << "user::process\n";
}
}

int main() {
    library::run(user::Task{});

    // range-based for: begin/end

    int x {4}, y {2};
    std::ranges::swap(x, y); // CPO
}
