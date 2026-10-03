#include <memory>
#include <iostream>

class ESFT : public std::enable_shared_from_this<ESFT> {
public:
    ESFT() {
        std::cout << "ESFT()" << std::endl;
    }

    ESFT(const ESFT&) = delete;
    ESFT& operator=(const ESFT&) = delete;

    ~ESFT() {
        std::cout << "~ESFT()" << std::endl;
    }
};

int main() {
   ESFT *esft = new ESFT();
//    :)
//    std::shared_ptr<ESFT> ptr = esft->shared_from_this();

   auto sp = std::shared_ptr<ESFT>(esft);
   auto sp2 = sp->shared_from_this();
   sp.reset();
   std::cout << "sp2.use_count() = " << sp2.use_count() << std::endl;
   // _M_enable_shared_from_this_with

//    ;)
    // int * a = new int(10);
    // std::shared_ptr<int> sp3(a), sp4(a);

//    .)
    // auto sp3 = std::shared_ptr<ESFT>(esft);
}
