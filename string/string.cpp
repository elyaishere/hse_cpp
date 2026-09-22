#include <cstdio>
#include <cstring>
#include <new>
#include <string>
#include <stdlib.h>

using namespace std;

void* operator new(size_t size) {
    if (size == 0) {
        size = 1;
    }

    if (void* ptr = malloc(size)) {
        printf("allocating %zu bytes\n", size);
        return ptr;
    }

    throw bad_alloc{};
}

void operator delete(void* ptr) noexcept {
    free(ptr);
}

void* operator new[](size_t size) {
    return ::operator new(size);
}

void operator delete[](void* ptr) noexcept {
    ::operator delete(ptr);
}

char* address0(const char* identifier, const char* domain) { 
    int iden_len = strlen(identifier); 
    int dom_len = strlen(domain); 
    char* addr = (char*)malloc(iden_len + dom_len + 2);
    strcpy(addr, identifier); 
    addr[iden_len] = '@'; 
    strcpy(addr + iden_len + 1, domain); 
    return addr;
}

string address1(const string& identifier, const string& domain) {
    string result;
    result.reserve(identifier.size() + domain.size() + 2);
 return identifier + '@' + domain;
}

int main () { 
    // char* t = address0("bs", "somewhere");
    // printf("%s\n", t); 
    // free(t);

    // https://godbolt.org/z/cd5MqzcKo
    address1(
        "some_long_string",
        "another_long_string"
    );
}
