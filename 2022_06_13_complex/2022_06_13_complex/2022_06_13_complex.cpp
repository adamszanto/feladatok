#pragma once
#include <iostream>
#include "Complex.h"

int main()
{
    Komplex k1;             // 0+0i
    Komplex k2 = 3.0;       // 3+0i
    Komplex k3(3.0, 4.0);   // 3+4i

    // operátor kiírás túltöltés, külsõ fgv barátként átdefiniáljuk
    std::cout << Komplex(3, 4) << std::endl; // 3+4i
    std::cout << Komplex(3, -4) << std::endl; // 3-4i

    // összeadás, szorzás
    Komplex c1 = 2;
    Komplex c2(3, 4);
    std::cout << c1 + c2 << std::endl; // 5+4i
    std::cout << c1 * c2 << std::endl; // 6+8i
    c1 += c2;
    std::cout << c1 << std::endl; // 5+4i

    std::cout << Komplex_sqrt(4.0) << std::endl; // 2+0i
    std::cout << Komplex_sqrt(-4.0) << std::endl; // 0+2i

}
