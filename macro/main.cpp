#define MY_SIZE SIZE * 2
#define SIZE 100
#define MY_SIZE_FUNC(size) (size) * 2

auto x = SIZE;
auto y = MY_SIZE;
auto z = MY_SIZE_FUNC(MY_SIZE);

#define STR(s) #s
#define XSTR(s) STR(s)

auto str = STR(4);
auto str1 = XSTR((SIZE));

#define CAT(s) s ## s
int catcat = 42;
auto cat = XSTR(CAT(a));

#define FOO BAR
#define BAR MAC
#define MAC FOO
auto foo = XSTR(MAC);

#define PRINT(arg, ...) print(arg __VA_OPT__(,) __VA_ARGS__)
auto a = __LINE__;
template <typename... Args>
void print(Args&&... args) {
    ((std::cout << std::forward<Args>(args) << ' '), ...);
}

void call() {
    PRINT(42);
}

