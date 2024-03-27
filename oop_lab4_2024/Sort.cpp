#include "Sort.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <algorithm>

Sort::Sort() {}

Sort::Sort(int numElements, int minValue, int maxValue) {
    srand(time(nullptr));
    for (int i = 0; i < numElements; ++i) {
        elements.push_back(rand() % (maxValue - minValue + 1) + minValue);
    }
}

Sort::Sort(std::initializer_list<int> initList) : elements(initList) {}

Sort::Sort(const std::vector<int>& vec, int numElements) {
    for (int i = 0; i < numElements; ++i) {
        elements.push_back(vec[i]);
    }
}

Sort::Sort(const std::vector<int>& vec) : elements(vec) {}

Sort::Sort(const char* str) {
    std::string s(str);
    elements = parseString(s);
}

void Sort::InsertSort(bool ascendent) {
    int n = elements.size();
    for (int i = 1; i < n; ++i) {
        int key = elements[i];
        int j = i - 1;

        if (ascendent) {
            while (j >= 0 && elements[j] > key) {
                elements[j + 1] = elements[j];
                j = j - 1;
            }
        }
        else {
            while (j >= 0 && elements[j] < key) {
                elements[j + 1] = elements[j];
                j = j - 1;
            }
        }
        elements[j + 1] = key;
    }
}

void Sort::QuickSort(bool ascendent)
{
    QuickSortHelper(0, elements.size() - 1, ascendent);
}

void Sort::QuickSortHelper(int low, int high, bool ascendent)
{
    if (low < high)
    {
        int pi = Partition(low, high, ascendent);
        QuickSortHelper(low, pi - 1, ascendent);
        QuickSortHelper(pi + 1, high, ascendent);
    }
}

int Sort::Partition(int low, int high, bool ascendent)
{
    int pivot = elements[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if ((ascendent && elements[j] < pivot) || (!ascendent && elements[j] > pivot))
        {
            i++;
            std::swap(elements[i], elements[j]);
        }
    }
    std::swap(elements[i + 1], elements[high]);
    return i + 1;
}

void Sort::BubbleSort(bool ascendent) {
    int n = elements.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (ascendent ? elements[j] > elements[j + 1] : elements[j] < elements[j + 1]) {
                swap(elements[j], elements[j + 1]);
            }
        }
    }
}

void Sort::Print() {
    for (int i : elements) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int Sort::GetElementsCount() {
    return elements.size();
}

int Sort::GetElementFromIndex(int index) {
    if (index < 0 || index >= elements.size()) {
        return -1;
    }
    return elements[index];
}

void Sort::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

std::vector<int> Sort::parseString(const std::string& str) {
    std::vector<int> result;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, ',')) {
        result.push_back(std::stoi(token));
    }
    return result;
}
