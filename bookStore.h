#include "book.h"

namespace kimsj2649068
{
    class bookStore
    {
    private:
        book b;
        bool available;
    public:
        bookStore(book b0 = book{1,0}, bool a0 = false) : b{b0}, available{a0} {}
        void print()
        {
            b.print();
            if (available == true) 
             std::cout << "available\n";
            else
             std::cout << "NOT available\n";
        }
        void setBook(const book& b0) { b = b0;}
        const book& getBook() const { return b; }
    };
}