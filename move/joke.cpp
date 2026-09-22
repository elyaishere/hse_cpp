#include <iostream>

using namespace std;

struct MyType {
    MyType() = default;
    MyType (float) {}

    operator float() { return 42.f; }
};
void f(float &&) {
    cout << "float\n";
}
void f(MyType &&) {
    cout << "MyType\n";
}
void g(float&& t, MyType&& m) {
    f(t), f(m);
}
int main () {
    g(2.f, MyType());
}
