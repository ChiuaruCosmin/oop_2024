#include "Sort.h"
#include <iostream>

int main() {
    Sort s1(10, 1, 100);
    Sort s2{ 5, 4, 3, 2, 1 };
    std::vector<int> vec = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };
    Sort s3(vec, 7);
    Sort s4("10,40,100,5,70");
    Sort s5(vec);

    std::cout << "Inainte de sortare: " << std::endl;
    std::cout << "s1: ";
    s1.Print();
    std::cout << "s2: ";
    s2.Print();
    std::cout << "s3: ";
    s3.Print();
    std::cout << "s4: ";
    s4.Print();
    std::cout << "s5: ";
    s5.Print();

    s1.InsertSort(true);
    s2.QuickSort(true);
    s3.BubbleSort(true);
    s4.InsertSort(true);
    s5.QuickSort(true);

    std::cout << "Dupa sortare: " << std::endl;
    std::cout << "s1: ";
    s1.Print();
    std::cout << "s2: ";
    s2.Print();
    std::cout << "s3: ";
    s3.Print();
    std::cout << "s4: ";
    s4.Print();
    std::cout << "s5: ";
    s5.Print();

    return 0;
}
