//
//  RationalNumber.h
//  RationalNumber
//
//  Created by Benjamin J. Benson on 9/14/15.
//  Copyright (c) 2015 Benjamin J. Benson. All rights reserved.
//

#ifndef __RationalNumber__RationalNumber__
#define __RationalNumber__RationalNumber__

#include <stdio.h>
#include <string>

#endif /* defined(__RationalNumber__RationalNumber__) */

class RationalNumber{
    
private:
    int Denominator;
    int Numerator;
    void reduce();
    //Computes the greatest common denominator.
    int gcd (int num1, int num2);
    
public:
    //-----------------------------------------------------------------
    //  Constructor: Sets up the rational number by ensuring a nonzero
    //  denominator and making only the numerator signed.
    //-----------------------------------------------------------------
    RationalNumber(int numer, int denom);
    
    //Default Constructor for this class;
    RationalNumber();
    
    //Copy Constructor
    RationalNumber(const RationalNumber &other);
    
    //getter method.
    int getNumerator() const;
    
    int getDenominator() const;
    
    //retrieves the reciporical of the this class.
    RationalNumber reciprocal();
    
    //adds one Rational Number to another rational number.
    RationalNumber add(const RationalNumber &other);
    
    //subtracts one rational number from another.
    RationalNumber subtract (const RationalNumber &other);
    
    //Multiply two rational number together
    RationalNumber multiply (const RationalNumber &other);
    
    //Divide two rational numbers
    RationalNumber divide (RationalNumber &other);
    
    //Equal to the other rational number.
    bool is_Like (const RationalNumber &other);
    
    //toString
    std::string to_String();
};