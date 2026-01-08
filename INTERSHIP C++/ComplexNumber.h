//
//  Complex Coordinates.h
//  Main
//
//  Created by DHRUTPATEL on 3/12/25.
//

#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <iostream>
#include <cmath>
#include <fstream> 
class ComplexNumber {
private:
    int Real, Imaginary;

public:
    // Constructors
    ComplexNumber();
    ComplexNumber(int real, int imaginary);

    // Accessors
    int get_Re() const;
    int get_Im() const;
    double get_Magnitude() const;

    // Mutators
    void Conjugate();

    // Operator overloads (friend functions)
    friend std::ostream& operator<<(std::ostream& out, const ComplexNumber& cn);
    friend std::istream& operator>>(std::istream& in, ComplexNumber& cn);
    
    friend ComplexNumber operator*(int n, const ComplexNumber& right);
    friend ComplexNumber operator*(const ComplexNumber& left, const ComplexNumber& right);
    friend ComplexNumber operator+(const ComplexNumber& left, const ComplexNumber& right);
    friend ComplexNumber operator-(const ComplexNumber& left, const ComplexNumber& right);
};

// Non-member function for comparison
bool operator<(const ComplexNumber& left, const ComplexNumber& right);

#endif
