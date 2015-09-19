//
//  main.cpp
//  RationalNumber
//
//  Created by Benjamin J. Benson on 9/14/15.
//  Copyright (c) 2015 Benjamin J. Benson. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <math.h>
#include "RationalNumber.h"
#include <vector>

using namespace std;
int main(){
    RationalNumber r1(6,8);
    RationalNumber r2(1,3);
    
    RationalNumber r3, r4, r5, r6, r7;
    
    cout << "First Rational Number: "<<r1.to_String()<<endl;
    cout << "Second Rational Number: "<<r2.to_String()<<endl;
    
    if(r1.is_Like(r2)){
        cout << "r1 and r2 are equal."<<endl;
    }else{
        cout<<"r1 and r2 are not equal."<<endl;
    }
    
    r3 = r1.reciprocal();
    cout << "The reciporical of r1 is: "<<r3.to_String()<<endl;
    
    r4 = r1.add(r2);
    r5 = r1.subtract(r2);
    r6 = r1.multiply(r2);
    r7 = r1.divide(r2);
    
    cout << "r1 + r2: "<<r4.to_String()<<endl;
    cout << "r1 - r2: "<<r5.to_String()<<endl;
    cout << "r1 * r2: "<<r6.to_String()<<endl;
    cout << "r1 / r2: "<<r7.to_String()<<endl;
    cout << "r1's value has not been changed: "<<r1.to_String()<<endl;
    cout << "r2's value has not been changed: "<<r2.to_String()<<endl;
    cout << ""<<endl;
}
