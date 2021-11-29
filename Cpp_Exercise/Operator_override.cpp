#include <iostream>

using namespace std;

// 复数类
// 其中定义了+和-的运算符重载函数，使得复数类可以进行+和-操作
class Complex
{
    friend Complex operator-(const Complex &, const Complex &);

public:
    Complex() = default;
    ~Complex() = default;

    Complex(double real, double imag) : mReal(real), mImag(imag) {}

    Complex(const Complex &tmp)
    {
        this->mReal = tmp.mReal;
        this->mReal = tmp.mImag;
    }

    Complex &operator=(const Complex &tmp)
    {
        this->mReal = tmp.mReal;
        this->mImag = tmp.mImag;
        return *this;
    }

    void PrintComplex() const
    {
        cout << mReal << "+" << mImag << "i" << endl;
    }

    Complex &operator+(const Complex &tmp)
    {
        this->mReal += tmp.mReal;
        this->mImag += tmp.mImag;
        return *this;
    }

private:
    double mReal;
    double mImag;
};

Complex operator-(const Complex &a, const Complex &b)
{
    return Complex(a.mReal - b.mReal, a.mImag - b.mImag);
}

int main()
{
    Complex a(1.1, 2.2);
    Complex b(3.3, 4.4);
    Complex c;
    c = a + b;
    c.PrintComplex();
    c = a - b;
    c.PrintComplex();

    return 0;
}