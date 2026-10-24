#pragma once
#include <iostream>

namespace kimsj2649068
{
    class book
    {
    private:
        int id; 
        int price;
        void testID()
        {
            if ( id < 1 || id > 1000 )
            {
                std::cout << "Invaild ID value!";
                std::exit(1);
            }
        }
         void testPrice()
        {
            if ( price < 0 || price > 50000 )
            {
                std::cout << "Invaild price value!";
                std::exit(1);
            }
        }
    public:
        book(int d = 1, int p = 0) : id{d}, price{p} //생성자에서는 쉼표로 연결!
        { testID(); testPrice(); }
        void input()
        {
            std::cout << "Enter your id: ";
            std::cin >> id;
            testID();

            std::cout << "Enter your price: ";
            std::cin >> price;
            testPrice();
        }
        void setID(int d)
        {
            id = d;
            testID();
        }
        void setPrice(int p)
        {
            price = p;
            testPrice();
        }
        void print() const
        {
            std::cout << "ID: " << id << ", price: " << price;
            std::cout << std::endl;
        }
        int getID() const {return id;}
        int getPrice() const {return price;}

        book operator++()
        {
            ++price;
            return book{id, price};
        }
        book operator++(int)
        {
            book temp{id,price};
            price++;
            return temp;
        }
        friend std::istream& operator>>( std::istream& is, book &b)
        {
            std::cout << "Enter your id: ";
            is >> b.id;
            std::cout << "Enter your price: ";
            is >> b.price;
            return is;
        }
        friend std::ostream& operator<<( std::ostream& os, const book &b)
        {
            os << "ID: " << b.id << ", price: " << b.price << "\n";
            return os;
        }
        friend bool operator==(const book &b1, const book &b2)
        {
            return b1.id == b2.id && b1.price == b2.price; // 클래스의 멤버 변수 id, price에 직접 접근 가능
        }
        friend int operator+(const book &b1, const book &b2)
        {
            return b1.price + b2.price;
        }

    };
}