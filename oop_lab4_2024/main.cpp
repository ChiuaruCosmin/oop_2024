#include <iostream>
#include "Number.h"

int main()
{
	Number n1("10110010", 2);
	Number n2("734", 8);
	Number n3("FE", 16);
	Number n4("1", 10);
	Number n10 = n2;

	if (n1 > n2) printf("n1 is bigger than n2\n"); else printf("n2 is bigger than n1\n");

	Number n5 = n3 + n4;
	Number n6 = n3 - n4;

	n5.Print();
	n6.Print();

	n3.SwitchBase(10);
	n4 += n2;
	n4.Print();
	n4 = n5 = n6;
	n4.Print();
	--n2;
	n2--;
	n2.Print();
}