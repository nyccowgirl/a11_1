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

#ifndef mystring_hpp
#define mystring_hpp

#include <iostream>

namespace cs_mystring {

/*
 
 TO UPDATE

 The MyString class can be used to create objects that store a fraction, including numerator
 and denominator. The following functions are available:

 Fraction(int inNum, int inDenom);
  post: The calling object has been created and initialized so that the numerator is the
        inNum parameter (with default of 0), and the denominator is the inDenom
        parameter (with default of 1). If inDenom is 0, program is aborted.
 
 friend Fraction operator+(const Fraction &left, const Fraction &right);
  post: Returns the Fraction determined by adding the Fraction (or integer) of the
        parameter "left" with the Fraction (or integer) of the paramenter "right".
 
 friend Fraction operator-(const Fraction &left, const Fraction &right);
  post: Returns the Fraction determined by subtracting the Fraction (or integer) of
        the parameter "right" from the Fraction (or integer) of the parameter "left".
 
 friend Fraction operator*(const Fraction &left, const Fraction &right);
  post: Returns the Fraction determined by multiplying the Fraction (or integer) of
        the parameter "left" by the Fraction (or integer) of the parameter "right".
 
 friend Fraction operator/(const Fraction &left, const Fraction &right);
  post: Returns the Fraction determined by dividing the Fraction (or integer) of the
        parameter "left" by the Fraction (or integer) of the parameter "right".
 
 friend bool operator<(const Fraction &left, const Fraction &right);
  post: Returns true if the Fraction (or integer) of the parameter "left" is less
        than the Fraction (or integer) of the parameter "right". Otherwise, returns
        false.
 
 friend bool operator<=(const Fraction &left, const Fraction &right);
  post: Returns true if the Fraction (or integer) of the parameter "left" is less
        than or equal to the Fraction (or integer) of the parameter "right".
        Otherwise, returns false.
 
 friend bool operator>(const Fraction &left, const Fraction &right);
  post: Returns true if the Fraction (or integer) of the parameter "left" is greater
        than the Fraction (or integer) of the parameter "right". Otherwise, returns
        false.
 
 friend bool operator>=(const Fraction &left, const Fraction &right);
  post: Returns true if the Fraction (or integer) of the parameter "left" is greater
        than or equal to the Fraction (or integer) of the parameter "right".
        Otherwise, returns false.
 
 friend bool operator==(const Fraction &left, const Fraction &right);
  post: Returns true if the Fraction (or integer) of the parameter "left" is equal to
        the Fraction (or integer) of the parameter "right". Otherwise, returns false.
 
 friend bool operator!=(const Fraction &left, const Fraction &right);
  post: Returns true if the Fraction (or integer) of the parameter "left" is not
        equal to the Fraction (or integer) of the parameter "right". Otherwise,
        returns false.
 
 Fraction operator+=(const Fraction &right);
  post: Returns the Fraction determined by adding the calling object with the Fraction (or
        integer) of the parameter "right".
 
 Fraction operator-=(const Fraction &right);
  post: Returns the Fraction determined by subtracting the calling object with the Fraction
        (or integer) of the parameter "right".
 
 Fraction operator*=(const Fraction &right);
  post: Returns the Fraction determined by multiplying the calling object by the Fraction
        (or integer) of the parameter "right".
 
 Fraction operator/=(const Fraction &right);
  post: Returns the Fraction determined by dividing the calling object by the Fraction (or
        integer) of the parameter "right".
 
 Fraction operator++();
  post: Returns the Fraction determined by incrementing the calling object by 1
        (pre-increment operator).
 
 Fraction operator++(int);
  post: Returns the original calling object after incrementing it by 1 (post-increment
        operator).
 
 Fraction operator--();
  post: Returns the Fraction determined be decrementing the calling object by 1
        (pre-decrement operator).
 
 Fraction operator--(int);
  post: Returns the original calling object after decrementing it by 1 (post-decrement
        operator).
 
 friend std::istream &operator<<(std::istream &in, Fraction &right);
  post: Reads a line from file in formats of W, W+N/D or N/D, and converts it into a
        Fraction object.

 friend std::ostream &operator<<(std::ostream &out, const Fraction &right);
  post: The calling object has been printed to the console window in the formats of W,
        W+N/D or N/D.
         
*/

class MyString
{
public:
    static const int MAX_SIZE = 151;
    MyString();
    MyString(const char *inCstring);
    MyString(const MyString &str);

    ~MyString();
    MyString operator=(const char *inCstring);
    MyString operator=(const MyString &right);

    int length() const;

    char operator[](int index) const;
    char& operator[](int index);
//    friend Fraction operator+(const Fraction &left, const Fraction &right);
//    friend Fraction operator-(const Fraction &left, const Fraction &right);
//    friend Fraction operator*(const Fraction &left, const Fraction &right);
//    friend Fraction operator/(const Fraction &left, const Fraction &right);
    friend bool operator<(const MyString &left, const MyString &right);
    friend bool operator<=(const MyString &left, const MyString &right);
    friend bool operator>(const MyString &left, const MyString &right);
    friend bool operator>=(const MyString &left, const MyString &right);
    friend bool operator==(const MyString &left, const MyString &right);
    friend bool operator!=(const MyString &left, const MyString &right);
//    Fraction operator+=(const Fraction &right);
//    Fraction operator-=(const Fraction &right);
//    Fraction operator*=(const Fraction &right);
//    Fraction operator/=(const Fraction &right);
//    Fraction operator++();
//    Fraction operator++(int);
//    Fraction operator--();
//    Fraction operator--(int);
    friend std::istream &operator>>(std::istream &in, MyString &right);
    friend std::ostream &operator<<(std::ostream &out, const MyString &right);

private:
    char *cstring;
};
}



#endif /* mystring_hpp */

/*
 ----- Testing basic String creation & printing
 string [0] = Wow
 string [1] = C++ is neat!
 string [2] =
 string [3] = a-z

 ----- Testing access to characters (using const)
 Whole string is abcdefghijklmnopqsrtuvwxyz
 now char by char: abcdefghijklmnopqsrtuvwxyz
 ----- Testing access to characters (using non-const)
 Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ

 ----- Testing relational operators between MyStrings
 Comparing app to apple
     Is left < right? true
     Is left <= right? true
     Is left > right? false
     Is left >= right? false
     Does left == right? false
     Does left != right ? true
 Comparing apple to
     Is left < right? false
     Is left <= right? false
     Is left > right? true
     Is left >= right? true
     Does left == right? false
     Does left != right ? true
 Comparing  to Banana
     Is left < right? true
     Is left <= right? true
     Is left > right? false
     Is left >= right? false
     Does left == right? false
     Does left != right ? true
 Comparing Banana to Banana
     Is left < right? false
     Is left <= right? true
     Is left > right? false
     Is left >= right? true
     Does left == right? true
     Does left != right ? false

 ----- Testing relations between MyStrings and char *
 Comparing he to hello
     Is left < right? true
     Is left <= right? true
     Is left > right? false
     Is left >= right? false
     Does left == right? false
     Does left != right ? true
 Comparing why to wackity
     Is left < right? false
     Is left <= right? false
     Is left > right? true
     Is left >= right? true
     Does left == right? false
     Does left != right ? true

 ----- Testing copy constructor and operator= on MyStrings
 original is cake, copy is fake
 original is cake, copy is fake
 after self assignment, copy is Copy Cat
 Testing pass & return MyStrings by value and ref
 after calling Append, sum is Binky
 val is winky
 after assign,  val is Binky
 Program ended with exit code: 0
 */
