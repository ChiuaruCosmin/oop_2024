#include "Number.h"

Number::Number(const char* value, int base)
{
    this->base = base;
    size = strlen(value);
    this->value = new char[size + 1];
    strcpy(this->value, value);
}

Number::Number(const Number& other) {
    base = other.base;
    size = other.size;
    value = new char[size + 1];
    strcpy(value, other.value);
}

Number::~Number() {
    delete[] value;
}

int toBase10(char* value, int base, int size) {
    int decimalValue = 0;
    int power = 1;
    for (int i = size - 1; i >= 0; --i) {

        std::string digitStr(1, value[i]);
        int digit = std::stoi(digitStr, 0, base);
        decimalValue += digit * power;
        power *= base;
    }

    return decimalValue;
}
char* FromBase10(int decimalValue, int newBase) {
    char* value = new char[32];
    int index = 0;
    while (decimalValue > 0) {
        int remainder = decimalValue % newBase;
        value[index++] = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
        decimalValue /= newBase;
    }
    if (index == 0) {
        value[index++] = '0';
    }
    value[index] = '\0';

    int start = 0;
    int end = index - 1;
    while (start < end) {
        std::swap(value[start], value[end]);
        start++;
        end--;
    }

    return value;
}

void Number::SwitchBase(int newBase) {
    if (newBase < 2 || newBase > 16) {
        std::cerr << "Invalid base. Base should be between 2 and 16." << std::endl;
        return;
    }

    int decimalValue = 0;
    int power = 1;
    for (int i = size - 1; i >= 0; --i) {

        std::string digitStr(1, value[i]);
        int digit = std::stoi(digitStr, 0, this->base);
        decimalValue += digit * power;
        power *= base;
    }

    base = newBase;
    delete[] value;
    value = new char[32];
    int index = 0;
    while (decimalValue > 0) {
        int remainder = decimalValue % base;
        value[index++] = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
        decimalValue /= base;

    }
    value[index] = '\0';

    int start = 0;
    int end = index - 1;
    while (start < end) {
        std::swap(value[start], value[end]);
        start++;
        end--;
    }

    size = index;
}

void Number::Print() {
    std::cout << "Value: " << value << " (Base: " << base << ")" << std::endl;
}

int Number::GetDigitsCount() {
    return size;
}

int Number::GetBase() {
    return base;
}

char Number::operator[](int index) {
    if (index >= 0 && index < size)
        return value[index];
    else
        return '\0';
}

bool Number::operator>(const Number& other) {
    int num1 = toBase10(this->value, this->base, this->size);
    int num2 = toBase10(other.value, other.base, other.size);

    return num1 > num2;
}

bool Number::operator<(const Number& other) {
    int num1 = toBase10(this->value, this->base, this->size);
    int num2 = toBase10(other.value, other.base, other.size);
    return num1 < num2;
}

bool Number::operator>=(const Number& other) {
    int num1 = toBase10(this->value, this->base, this->size);
    int num2 = toBase10(other.value, other.base, other.size);

    return num1 >= num2;
}

bool Number::operator<=(const Number& other) {
    int num1 = toBase10(this->value, this->base, this->size);
    int num2 = toBase10(other.value, other.base, other.size);
    return num1 <= num2;
}

bool Number::operator==(const Number& other) {
    int num1 = toBase10(this->value, this->base, this->size);
    int num2 = toBase10(other.value, other.base, other.size);
    return num1 == num2;
}

bool Number::operator!=(const Number& other) {
    int num1 = toBase10(this->value, this->base, this->size);
    int num2 = toBase10(other.value, other.base, other.size);
    return num1 != num2;
}

Number operator + (Number& n1, Number& n2)
{
    int higher_base;
    if (n1.base < n2.base) {
        higher_base = n2.base;
    }
    else {
        higher_base = n1.base;
    }

    int num1 = toBase10(n1.value, n1.base, n1.size);
    int num2 = toBase10(n2.value, n2.base, n2.size);
    int sum10 = num1 + num2;
    char* value = FromBase10(sum10, higher_base);
    return Number(value, higher_base);
}

Number& Number::operator += (Number& n)
{
    int higher_base;
    if (this->base < n.base) {
        higher_base = n.base;
    }
    else {
        higher_base = this->base;
    }

    int num1 = toBase10(this->value, this->base, this->size);
    int num2 = toBase10(n.value, n.base, n.size);
    num1 += num2;
    char* temp = FromBase10(num1, higher_base);

    if (this->value != nullptr) {
        delete[] this->value;
    }
    this->value = new char[strlen(temp) + 1];
    strcpy(this->value, temp);
    this->base = higher_base;

    return (*this);
}

Number operator - (Number& n1, Number& n2)
{
    int higher_base;
    if (n1.base < n2.base) {
        higher_base = n2.base;
    }
    else {
        higher_base = n1.base;
    }

    int num1 = toBase10(n1.value, n1.base, n1.size);
    int num2 = toBase10(n2.value, n2.base, n2.size);
    int sum10 = num1 - num2;
    char* value = FromBase10(sum10, higher_base);
    return Number(value, higher_base);
}

Number& Number::operator=(const Number& n) {
    base = n.base;
    size = n.size;
    if (this->value != nullptr) {
        delete[]value;
    }

    value = new char[size + 1];
    strcpy(value, n.value);

    return (*this);
}

Number& Number::operator--() {
    if (size > 1) {
        char* newValue = new char[size];
        std::strcpy(newValue, value + 1);
        delete[] value;
        this->value = new char[size];
        strcpy(this->value, newValue);
        --size;
    }
    else {
        delete[] value;
        value = new char[2];
        value[0] = '0';
        value[1] = '\0';
        size = 1;
    }
    return *this;
}

Number& Number::operator--(int) {
    if (size > 1) {
        value[size - 1] = '\0';
        --size;
    }
    else {
        delete[] value;
        value = new char[2];
        value[0] = '0';
        value[1] = '\0';
        size = 1;
    }

    return (*this);
}