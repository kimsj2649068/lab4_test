#pragma once
#include <iostream>
#include <string>

namespace kimsj2649068
{
    class book
    {
    private:
        int id; 
        int price;
        std::string title;
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
        book(const std::string& t = "No Title Yet", int d = 1, int p = 0) : title{t}, id{d}, price{p} //생성자에서는 쉼표로 연결!
        { testID(); testPrice(); }
        void input()
        {
            std::cout << "Enter your title: ";
            std::getline(std::cin >> std::ws, title);

            std::cout << "Enter your id: ";
            std::cin >> id;
            testID();

            std::cout << "Enter your price: ";
            std::cin >> price;
            testPrice();

        }
        void setTitle(std::string t)
        {
            title = t;
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
            std::cout << "title: " << title << ", ID: " << id << ", price: " << price;
            std::cout << std::endl;
        }
        const std::string& getTitle() const {return title;}
        int getID() const {return id;}
        int getPrice() const {return price;}

        book& operator++() // const 쓰면 안돼.. price가 바뀌니까!
        {
            ++price;
            return (*this);
            //return book{title, id, price};
        }
        book operator++(int)
        {
            book temp{*this};
            ++(*this); //price++;
            return temp;
        }
        book& operator+=(int p)
        {
            this->price += p;
            return *this;
        }
        friend std::istream& operator>>( std::istream& is, book &b)
        {
            std::cout << "Enter your title: ";
            std::getline(is >> std::ws, b.title);

            std::cout << "Enter your id: ";
            is >> b.id;

            std::cout << "Enter your price: ";
            is >> b.price;
            return is;
        }
        friend std::ostream& operator<<( std::ostream& os, const book &b)
        {
            os << "title: " << b.title << ", ID: " << b.id << ", price: " << b.price << "\n";
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