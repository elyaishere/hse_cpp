#include <iostream>
#include <vector>

namespace transfer {
    struct Bomb {
        void foo() {}
        int id;
    };
    void Open(const Bomb&) { }
}

void func_1() {
    auto bomb = transfer::Bomb{42};
    std::cout;
    transfer::Open(bomb);
}

void signal(...) {
    std::cout << "::signal(...)\n";
}
namespace space {
    struct Stub;
}

struct T {
    T (space::Stub)  {
        std::cout << "T(Stub)\n";
    }
    T(const T&) = delete;
    T& operator=(const T&) = delete;
    T& operator=( T&&) {};
};
namespace space {
    struct Stub {
        operator T() {
            std::cout << "Stub::T()\n";
        };
    };
    void signal(Stub) {
        std::cout << "space::signal(Stub)\n";
    }
}

void func_2() {
    space::Stub s;
    signal(s);
    space::signal(s);
    (signal)(s);
    using signal = int;
    signal(s);
}

namespace box {
template <class T>
struct TStuff {
    T value;
};
} // box

namespace tunnel {
struct Ticket {};
void route(const box::TStuff<Ticket>&) {
    std::cout << "tunnel::route(TStuff<Ticket>)\n";
}
template<class T> void probe(int) { }
} // namespace tunnel

namespace legacy {
struct IPhone10 {};
void use(const IPhone10&) {
    std::cout << "legacy::use(IPhone10)\n";
}
}
namespace modern {
struct IPhone17 : legacy::IPhone10 {};
// void use(const IPhone17&) {
//     std::cout << "modern::use(IPhone10)\n";
// }
}

void func_3() {
    box::TStuff<tunnel::Ticket> stuff;
    route(stuff);
    use(modern::IPhone17{});

    tunnel::probe<tunnel::Ticket>(42);
}

namespace close {
class Holder {
public:
    explicit Holder(int value) : value_(value) {}
    friend bool operator==(Holder lhs, Holder rhs) {
        return lhs.value_ == rhs.value_;
    }
    friend void get(Holder value) {
        std::cout << "fff\n";
    }
private:
    int value_;
};

void get(Holder value);
}

void func_4() {
    close::Holder one{1};
    close::Holder anotherone{1};

    std::cout << (one == anotherone) << std::endl;
    // где определено?
    get(one);
}

namespace storage {
class Buffer {
public:
    Buffer(std::string label, std::vector<int> data)
        : label_(std::move(label)), data_(std::move(data)) {}

    friend void swap(Buffer& lhs, Buffer& rhs) noexcept {
        std::cout << "storage::swap(Buffer&, Buffer&)\n";
        lhs.label_.swap(rhs.label_);
        lhs.data_.swap(rhs.data_);
    }

private:
    std::string label_;
    std::vector<int> data_;
};
}

template <typename T>
void generic_swap(T& lhs, T& rhs) {
    using std::swap;
    swap(lhs, rhs);
}

void func_5() {
    storage::Buffer left{"left", {1, 2, 3}};
    storage::Buffer right{"right", {4, 5}};
    generic_swap(left, right);

    int x = 1;
    int y = 2;
    generic_swap(x, y);
}

namespace puzzle {
namespace backstage {
struct Pass {};
void call(void (*function)()) {
    std::cout << "backstage::call\n";
    function();
}
} // backstage

void hello() {
    std::cout << "hello\n";
}
void hello(backstage::Pass pass);

void run() {
    call(hello);
}} // namespace puzzle

void func_6() {
    puzzle::run();
}

int main () {
    func_6();
}
