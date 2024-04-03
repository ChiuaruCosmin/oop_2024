#pragma once
#include <iostream>
#include <string>
using namespace std;
class Number
{
	char* value;
	int base;
	int size;
public:
	Number(const char* value, int base);
	Number(const Number& other);
	~Number();

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount();
	int  GetBase();
	char operator[](int index);
	bool operator>(const Number& other);
	bool operator<(const Number& other);
	bool operator>=(const Number& other);
	bool operator<=(const Number& other);
	bool operator==(const Number& other);
	bool operator!=(const Number& other);
	friend Number operator + (Number& n1, Number& n2);
	friend Number operator - (Number& n1, Number& n2);
	Number& operator=(const Number& n);
	Number& operator += (Number& n);
	Number& operator--();
	Number& operator--(int);
};

int toBase10(char* value, int base, int size);
char* FromBase10(int decimalValue, int newBase);