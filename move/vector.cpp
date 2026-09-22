#include <cstdio>
#include <type_traits>
#include <vector>

struct MoveAndCopy {
    MoveAndCopy() {
        std::puts("creating");
    }

    MoveAndCopy(const MoveAndCopy&) {
        std::puts("copying");
    }

    MoveAndCopy(MoveAndCopy&&) /*noexcept*/ {
        std::puts("moving");
    }

    MoveAndCopy& operator=(MoveAndCopy&&) = default;
};

int main() {
    std::vector<MoveAndCopy> objects(2);

    objects.reserve(objects.capacity() + 3);

    std::puts("<----->");
    objects.push_back(MoveAndCopy());
    std::puts("-----");
    objects.emplace_back(MoveAndCopy());
    std::puts("-----");
    objects.emplace_back();
    std::puts("<----->");
}
