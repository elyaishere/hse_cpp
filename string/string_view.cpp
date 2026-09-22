#include <string_view>
#include <string>
#include <vector>

using namespace std;

void foo(const string &s);
void bar(const string &s);

string get_str();

string_view get_view() {
    string s{"hello"};
    return s;
}

string_view get_view(const string &s) {
    return s;
}

int main() {
    string_view hw = "hello world";
    // foo(hw);

    auto s = get_str();
    const string & rs = get_str();
    string&& rrs = get_str();
    string_view sw = get_str();

    const auto boom = get_view("hello world");

    vector<string> ss{{"oops"}};
    string_view sw(ss[0]);
    for (int i = 0; i < 30; ++i) {
        ss.emplace_back("bye-bye-bye");
    }

}
