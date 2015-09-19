//
//  RationalNumber.cpp
//  RationalNumber
//
//  Created by Benjamin J. Benson on 9/14/15.
//  Copyright (c) 2015 Benjamin J. Benson. All rights reserved.
//
#include <string>
#include "RationalNumber.h"
#include <cmath>

/********************************************************
* The default constructor this this class.
* 
*
********************************************************/
RationalNumber::RationalNumber(int numer, int denom){
    if (denom == 0)
        denom = 1;
    
    // Make the numerator "store" the sign
    if (denom < 0)
    {
        numer = numer * -1;
        denom = denom * -1;
    }
    
    RationalNumber::Numerator = numer;
    RationalNumber::Denominator = denom;
    reduce();
}

RationalNumber::RationalNumber(){
    Numerator = 0;
    Denominator = 0;
}

RationalNumber::RationalNumber(const RationalNumber &other){
    Numerator = other.Numerator;
    Denominator = other.Denominator;
}

int RationalNumber::getDenominator() const{
    return Denominator;
}

int RationalNumber::getNumerator() const{
    return Numerator;
}

RationalNumber RationalNumber:: reciprocal(){
    return RationalNumber(Denominator, Numerator);
}

RationalNumber RationalNumber::add(const RationalNumber &other){
    int commonDenominator = Denominator * other.getDenominator();
    int numerator1 = Numerator * other.getDenominator();
    int numerator2 = other.getNumerator() * Denominator;
    int sum = numerator1 + numerator2;
    
    return RationalNumber (sum, commonDenominator);
}

RationalNumber RationalNumber::subtract (const RationalNumber &other){
    int commonDenominator = Denominator * other.getDenominator();
    int numerator1 = Numerator * other.getDenominator();
    int numerator2 = other.getNumerator() * Denominator;
    int difference = numerator1 - numerator2;
    
    return RationalNumber (difference, commonDenominator);
}

RationalNumber RationalNumber::multiply(const RationalNumber &other){
    int numer = Numerator * other.getNumerator();
    int denom = Denominator * other.getDenominator();
    
    return  RationalNumber (numer, denom);
}

RationalNumber RationalNumber::divide( RationalNumber &other){
    return multiply (other.reciprocal());
}

bool RationalNumber::is_Like (const RationalNumber &other) {
    if(other.getDenominator()==Denominator && other.getNumerator() ==Numerator){
        return true;
    }
    return false;
   //numerator == op2.getNumerator && denominator == op2.getDenominator;
}

std::string RationalNumber::to_String(){
    std::string result;
    
    if (Numerator == 0)
        result = "0";
    else
        if (Denominator == 1)
            result = std::to_string(Numerator) + "";
        else
            result = std::to_string(Numerator) + "/" + std::to_string(Denominator);
    
    return result;
}

/***********************************************************
 *
 **********************************************************/
void RationalNumber::reduce(){
    if (Numerator != 0){
        int common = gcd ((std::fabs(Numerator)), Denominator);
    
        Numerator = Numerator / common;
        Denominator = Denominator / common;
    }
}

//
int RationalNumber::gcd(int num1, int num2){
    while (num1 != num2)
        if (num1 > num2)
            num1 = num1 - num2;
        else
            num2 = num2 - num1;
    
    return num1;
}











