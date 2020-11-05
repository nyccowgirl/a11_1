/*
 Trang Hoang
 CS110B
 Dave Harden
 11/10/20
 mystring.hpp
 
 Assignment 11.1
 
 Write a string class. To avoid conflicts with other similarly named classes, we will call
 our version MyString. This object is designed to make working with sequences of characters
 a little more convenient and less error-prone than handling raw c-strings, (although it
 will be implemented as a c-string behind the scenes). The MyString class will handle
 constructing strings, reading/printing, and accessing characters. In addition, the
 MyString object will have the ability to make a full deep-copy of itself when copied.
 
 Created by nyccowgirl on 11/10/20.
 Copyright © 2020 nyccowgirl. All rights reserved.
*/

#include "mystring.hpp"
#include <iostream>
#include <cassert>
using namespace std;

namespace cs_mystring {

/*
  
 Class Invariant: a MyString object has one char data member: cstring, which stores an
 array of characters.
    
*/

    MyString::MyString() {
        cstring = new char(1);
        strcpy(cstring, "");
    }






    MyString::MyString(const char *inCstring) {
        cstring = new char(strlen(inCstring) + 1);
        strcpy(cstring, inCstring);
    }





MyString::MyString(const MyString &str) {
    cstring = new char(str.length() + 1);
    strcpy(cstring, str.cstring);
}




MyString::~MyString() {
    delete [] cstring;
}



MyString MyString::operator=(const char *inCstring) {
    if (strcmp(cstring, inCstring) != 0) {
        delete [] cstring;
        cstring = new char[strlen(inCstring) + 1];
        strcpy(cstring, inCstring);
    }
    return *this;
}



MyString MyString::operator=(const MyString &right) {
    if (this != &right){
        delete [] cstring;
        cstring = new char[strlen(right.cstring) + 1];
        strcpy(cstring, right.cstring);
    }
    return *this;
}




int MyString::length() const {
    return (int)strlen(cstring);
}





char MyString::operator[](int index) const
{
    assert(index >= 0 && index < strlen(cstring));
    return cstring[index];
}

char& MyString::operator[](int index)
{
    assert(index >= 0 && index < strlen(cstring));
    return cstring[index];
}
//
//
//
//
//
//
//    Fraction operator+(const Fraction &left, const Fraction &right) {
//        int sum;
//        Fraction temp;
//
//        sum = (left.numerator * right.denominator) + (right.numerator * left.denominator);
//        temp = Fraction(sum, (left.denominator * right.denominator));
//        temp.simplify();
//        return temp;
//    }
//
//
//
//
//
//
//    Fraction operator-(const Fraction &left, const Fraction &right) {
//        int diff;
//        Fraction temp;
//
//        diff = (left.numerator * right.denominator) - (right.numerator * left.denominator);
//        temp = Fraction(diff, (left.denominator * right.denominator));
//        temp.simplify();
//        return temp;
//    }
//
//
//
//
//
//
//    Fraction operator*(const Fraction &left, const Fraction &right) {
//        Fraction temp;
//
//        temp = Fraction((left.numerator * right.numerator),
//                        (left.denominator * right.denominator));
//        temp.simplify();
//        return temp;
//    }
//
//
//
//
//
//
//    Fraction operator/(const Fraction &left, const Fraction &right) {
//        Fraction temp;
//
//        temp = Fraction((left.numerator * right.denominator),
//                        (left.denominator * right.numerator));
//        temp.simplify();
//        return temp;
//    }
//
//
//
//
//
//
    bool operator<(const MyString &left, const MyString &right) {
        return strcmp(left.cstring, right.cstring) < 0;
    }






    bool operator<=(const MyString &left, const MyString &right) {
        return strcmp(left.cstring, right.cstring) <= 0;
    }






    bool operator>(const MyString &left, const MyString &right) {
        return strcmp(left.cstring, right.cstring) > 0;
    }





    bool operator>=(const MyString &left, const MyString &right) {
        return strcmp(left.cstring, right.cstring) >= 0;
    }






    bool operator==(const MyString &left, const MyString &right) {
        return strcmp(left.cstring, right.cstring) == 0;
    }






    bool operator!=(const MyString &left, const MyString &right) {
        return strcmp(left.cstring, right.cstring) != 0;
    }






//    Fraction Fraction::operator+=(const Fraction &right) {
//        *this = *this + right;
//        return *this;
//    }
//
//
//
//
//
//
//    Fraction Fraction::operator-=(const Fraction &right) {
//        *this = *this - right;
//        return *this;
//    }
//
//
//
//
//
//
//    Fraction Fraction::operator*=(const Fraction &right) {
//        *this = *this * right;
//        return *this;
//    }
//
//
//
//
//
//
//    Fraction Fraction::operator/=(const Fraction &right) {
//        *this = *this / right;
//        return *this;
//    }
//
//
//
//
//
//
//    Fraction Fraction::operator++() {
//    //    *this = *this + 1;
//        *this += 1;
//        return *this;
//    }
//
//
//
//
//
//
//    Fraction Fraction::operator++(int) {
//        Fraction temp(*this);
//    //    *this = *this + 1;
//        *this += 1;
//        return temp;
//    }
//
//
//
//
//
//
//    Fraction Fraction::operator--() {
//    //    *this = *this - 1;
//        *this -= 1;
//        return *this;
//    }
//
//
//
//
//
//
//    Fraction Fraction::operator--(int) {
//        Fraction temp(*this);
//    //    *this = *this - 1;
//        *this -= 1;
//        return temp;
//    }
//
//
//


istream &operator>>(istream &in, MyString &right) {
    while (isspace(in.peek())){
        in.ignore();
    }
    
    char temp[MyString::MAX_SIZE + 1];
    in.getline(temp, MyString::MAX_SIZE, ':');      // Need to adjust
    delete [] right.cstring;
    right.cstring = new char[strlen(temp) + 1];
    strcpy(right.cstring, temp);
//    in >> target.units;
    
    return in;
}

ostream &operator<<(ostream &out, const MyString &right) {
    out << right.cstring;
    return out;
}
//
//
//
//    istream &operator>>(istream &in, Fraction &right) {
//        int temp, whole = 0, num = 0, den = 1;
//        bool frac = false;
//
//        do {
//            in >> temp;
//
//            if ((in.peek() == '+') || ((in.peek() == '\n') && !(frac))) {
//                whole = temp;
//                if (in.peek() == '+') {
//                    in.ignore();
//                }
//            } else if (in.peek() == '/') {
//                num = temp;
//                frac = true;
//                in.ignore();
//            } else {
//                den = temp;
//            }
//
//        } while (in.peek() != '\n');
//
//        if (whole < 0) {
//            right.numerator = (whole * den) - num;
//        } else {
//            right.numerator = (whole * den) + num;
//        }
//        right.denominator = den;
//        right.simplify();
//        return in;
//    }
//
//
//
//
//
//
//    ostream &operator<<(ostream &out, const Fraction &right) {
//        if (right.denominator == 1) {
//            out << right.numerator;
//        } else if ((right.numerator < 0) && (abs(right.numerator) > right.denominator)) {
//            out << "-" << (abs(right.numerator) / right.denominator) << "+";
//            out << (abs(right.numerator) % right.denominator) << "/" << right.denominator;
//        } else if (right.numerator > right.denominator) {
//            out << (right.numerator / right.denominator) << "+";
//            out << (right.numerator % right.denominator) << "/" << right.denominator;
//        } else {
//            out << right.numerator << "/" << right.denominator;
//        }
//        return out;
//    }
//
//
//
//
//
//
//    // This private member function reduces, and replaces numerator and denominator for
//    // simplified fraction
//
//    void Fraction::simplify() {
//        int max;
//        bool neg = false;
//
//        // To address negative or zero fractions
//        if (numerator < 0) {
//            neg = !neg;
//            numerator *= -1;
//        } else if (numerator == 0) {
//            denominator = 1;
//        }
//
//        if (denominator < 0) {
//            neg = !neg;
//            denominator *= -1;
//        }
//
//        // To reduce by common divisors
//        if (numerator < denominator) {
//            max = numerator;
//        } else if (denominator < numerator) {
//            max = denominator;
//        } else {
//            numerator = denominator = max = 1;
//        }
//
//        for (int i = max; i > 1; i--) {
//            if ((numerator % i == 0) && (denominator % i == 0)) {
//                numerator /= i;
//                denominator /= i;
//            }
//        }
//
//        // To put back as negative, if initial fraction was net negative
//        if (neg) {
//            numerator *= -1;
//        }
//    }

}

