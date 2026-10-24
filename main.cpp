#include "bookStore.h"

int main()
{
    using namespace kimsj2649068;

    book b1; std::cout << "book1: \n"; std::cin >> b1; std::cout << b1;
    book b2; std::cout << "book2: \n"; std::cin >> b2; std::cout << b2;

    std::cout << ++b2;
    std::cout << b2++;
    std::cout << b2;

    if ( b1 == b2 )
        std::cout << "same\n";
    else
        std::cout << "different\n";

    std::cout << b1 + b2 << '\n';

    return 0;
}

// 3. main.cpp: 테스트
// 두번째 객체에 전위증가연산자 적용한 것을 표준스트림으로 출력
// 두번째 객체에 후위증가연산자 적용한 것을 표준스트림으로 출력
// 두번째 객체를 표준스트림으로 출력
// 두 객체를 비교연산자를 이용하여 비교하여 true면 same, 그렇지 않으면 different를 콘솔창에 출력
// 두 객체를 +이항연산자를 이용하여 더한 값을 표준스트림으로 출력
