#include <iostream>
#include "Math.h"

int main() {
    std::cout << "Add(2, 3): " << Math::Add(2, 3) << std::endl;
    std::cout << "Add(2, 3, 4): " << Math::Add(2, 3, 4) << std::endl;
    std::cout << "Add(2.5, 3.5): " << Math::Add(2.5, 3.5) << std::endl;
    std::cout << "Add(2.5, 3.5, 4.5): " << Math::Add(2.5, 3.5, 4.5) << std::endl;
    std::cout << "Mul(2, 3): " << Math::Mul(2, 3) << std::endl;
    std::cout << "Mul(2, 3, 4): " << Math::Mul(2, 3, 4) << std::endl;
    std::cout << "Mul(2.5, 3.5): " << Math::Mul(2.5, 3.5) << std::endl;
    std::cout << "Mul(2.5, 3.5, 4.5): " << Math::Mul(2.5, 3.5, 4.5) << std::endl;

    int v[101];
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v[4] = 5;

    std::cout << "Add(5, v[1, 2, 3, 4, 5]): " << Math::Add(5, v) << std::endl;

    const char* s1 = "Hello ";
    const char* s2 = "World";

    std::cout << "Add(Hello ,World): " << Math::Add(s1,s2);

    return 0;
}