#include <iostream>
#include "Tmain.hpp"
void subject_tests(void)
{
    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}
int main(void)
{
    std::cout << "Subject tests vvv" << std::endl;
    subject_tests();

    int a = 1;
    int b = 2;
    float c(a + 0.42);
    float d(b + 0.24);

    swap(a, b);
    swap<float>(c, d);
    std::cout << "\n--Testing SWAP (pre-swap a == 1 ; b == 2; c == 1.42\
 ; d = 2.24" << std::endl;

    std::cout << "a=" << a << ":" << "b=" << b << std::endl;
    std::cout << "c=" << c << ":" << "d=" << d << std::endl;

    std::cout << "\n--Testing MAX" << std::endl;
    std::cout << "max(2 vs 1): [" << max(a, b) << "]\nmax(1.42 vs 2.24): [" << max(d, c) << "]" << std::endl;

    std::cout << "\n--Testing MIN" << std::endl;
    std::cout << "min(2 vs 1): [" << min(a, b) << "]\nmin(1.42 vs 2.24): [" << min(d, c) << "]" << std::endl;
}
