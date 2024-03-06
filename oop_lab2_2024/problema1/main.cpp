#include "NumberList.h"

int main() {
    NumberList list;
    list.Init();
    list.Add(3);
    list.Add(6);
    list.Add(8);
    list.Add(2);
    list.Add(14);
    list.Add(221);
    list.Add(12);
    list.Add(21);
    list.Add(87);
    list.Add(45);

    list.Sort();
    list.Print();

    return 0;
}
