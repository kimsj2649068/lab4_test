#include "book.h"

namespace kimsj2649068
{
    void parVal(book b) {b += 1000;}
    void parRef(book &r) {r += 1000;}
    void parPtr(book *p) {*p += 1000;}

    book retVal(book b) {b += 1000; return b;}
    book& retRef(book& r) {r += 1000; return r;}
    book* retVal(book* p) {*p += 1000; return p;}
}

int main()
{
    using namespace kimsj2649068;

    book b = book{"title1", 1, 10000}; std::cout << b;
    parVal(b); std::cout << b;
    book& r{b}; std::cout << r;
    parRef(r); std::cout << r;
    book* p{&b}; std::cout << *p;
    parPtr(p); std::cout << *p;

    b = book{"title2", 2, 20000}; std::cout << b;
    std::cout << retVal(b);
    std::cout << r; 
    std::cout << retRef(r);
    std::cout << *p;
    std::cout << *retVal(p);

    book* ptr( new book );
    (*ptr).setTitle("title3"); ptr->setID(3); ptr->setPrice(30000);
    std::cout << *ptr;
    delete ptr;

    return 0;
    
}