#ifndef SORT_H
#define SORT_H
#include <vector>
#include <string>

class Sort
{
private:
    std::vector<int> elements;

public:
    Sort();
    Sort(int numElements, int minValue, int maxValue);
    Sort(std::initializer_list<int> initList);
    Sort(const std::vector<int>& vec, int numElements);
    Sort(const char* str);
    Sort(const std::vector<int>& vec);

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);

private:
    void swap(int& a, int& b);
    std::vector<int> parseString(const std::string& str);
    void QuickSortHelper(int low, int high, bool ascendent);
    int Partition(int low, int high, bool ascendent);
};

#endif