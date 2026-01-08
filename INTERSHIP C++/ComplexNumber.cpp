#include "ComplexNumber.h"
#include <fstream> 
// Default constructor
ComplexNumber::ComplexNumber() : Real(0), Imaginary(0) {}

//  constructor
ComplexNumber::ComplexNumber(int real, int imaginary) : Real(real), Imaginary(imaginary) {}

// Accessor functions
int ComplexNumber::get_Re() const {
    return Real;
}

int ComplexNumber::get_Im() const {
    return Imaginary;
}

double ComplexNumber::get_Magnitude() const {
    return std::sqrt(Real * Real + Imaginary * Imaginary);
}

// Mutator function
void ComplexNumber::Conjugate() {
    Imaginary = -Imaginary;
}

// Overloaded stream operators
std::ostream& operator<<(std::ostream& out, const ComplexNumber& cn) {
    out << cn.Real;
    if (cn.Imaginary >= 0) {
        out << " + " << cn.Imaginary << "i";
    } else {
        out << " - " << -cn.Imaginary << "i";
    }
    return out;
}

std::istream& operator>>(std::istream& in, ComplexNumber& cn) {
    char plus, i;
    in >> cn.Real >> plus >> cn.Imaginary >> i;
    return in;
}

// Overloaded arithmetic operators
ComplexNumber operator*(int n, const ComplexNumber& right) {
    return ComplexNumber(n * right.Real, n * right.Imaginary);
}

ComplexNumber operator*(const ComplexNumber& left, const ComplexNumber& right) {
    int realPart = left.Real * right.Real - left.Imaginary * right.Imaginary;
    int imaginaryPart = left.Real * right.Imaginary + left.Imaginary * right.Real;
    return ComplexNumber(realPart, imaginaryPart);
}

ComplexNumber operator+(const ComplexNumber& left, const ComplexNumber& right) {
    return ComplexNumber(left.Real + right.Real, left.Imaginary + right.Imaginary);
}

ComplexNumber operator-(const ComplexNumber& left, const ComplexNumber& right) {
    return ComplexNumber(left.Real - right.Real, left.Imaginary - right.Imaginary);
}

// Comparison operator
bool operator<(const ComplexNumber& left, const ComplexNumber& right) {
    return left.get_Magnitude() < right.get_Magnitude();
}
