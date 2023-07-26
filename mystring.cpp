/*
* Program: mystring.cpp (Assignment 11P: Classes with DM 1)
* Author: Matt Aaron Magnaye
* Instructor: Professor David Harden
* Date: 07/25/2023
* Description: Writing string class called MyString.
*
*/
#include "mystring.h"
#include <cstring>

namespace cs_mystring {

    // Constructor: Initialize MyString with a c-string.
    MyString::MyString(const char* s) {
        cstring = new char[strlen(s) + 1];
        strcpy(cstring, s);
    }

    // Copy constructor: Initialize MyString with another MyString.
    MyString::MyString(const MyString& source) {
        cstring = new char[strlen(source.cstring) + 1];
        strcpy(cstring, source.cstring);
    }

    // Destructor: Deallocates the memory that was previously reserved for this string.
    MyString::~MyString() {
        delete[] cstring;
    }

    // Overloaded assignment operator to copy the content from one 
    // MyString to another.
    MyString& MyString::operator=(const MyString& right) {
        if (this != &right) {
            delete[] cstring;
            cstring = new char[strlen(right.cstring) + 1];
            strcpy(cstring, right.cstring);
        }
        return *this;
    }

    // Overloaded [] operator to get the character at a specific index.
    char MyString::operator[](int index) const {
        return cstring[index];
    }

    // Overloaded [] operator to get/set the character at a specific index.
    char& MyString::operator[](int index) {
        return cstring[index];
    }

    // Overloaded operators for comparing two MyString objects.
    bool operator<(const MyString& left, const MyString& right) {
        return strcmp(left.cstring, right.cstring) < 0;
    }

    bool operator<=(const MyString& left, const MyString& right) {
        return strcmp(left.cstring, right.cstring) <= 0;
    }

    bool operator>(const MyString& left, const MyString& right) {
        return strcmp(left.cstring, right.cstring) > 0;
    }

    bool operator>=(const MyString& left, const MyString& right) {
        return strcmp(left.cstring, right.cstring) >= 0;
    }

    bool operator==(const MyString& left, const MyString& right) {
        return strcmp(left.cstring, right.cstring) == 0;
    }

    bool operator!=(const MyString& left, const MyString& right) {
        return strcmp(left.cstring, right.cstring) != 0;
    }

    // Overloaded stream insertion operator to output the content of the MyString.
    std::ostream& operator<<(std::ostream& out, const MyString& source) {
        out << source.cstring;
        return out;
    }

    // Returns the length of the c-string in this MyString.
    int MyString::length() const {
        return strlen(cstring);
    }
}
