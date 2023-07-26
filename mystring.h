/*
* Program: mystring.h (Assignment 11P: Classes with DM 1)
* Author: Matt Aaron Magnaye
* Instructor: Professor David Harden
* Date: 07/25/2023
* Description: Writing string class called MyStringg.
*
*/
#include <iostream>

namespace cs_mystring {

    // MyString class for representing and manipulating sequences of characters.
    class MyString {
        private:
            char* cstring;  // private variable to store the c-string.

        public:
            // Constructor: Initialize MyString with a c-string.
            // If no argument is provided, it defaults to an empty string.
            MyString(const char* s = "");

            // Copy constructor: Initialize MyString with another MyString.
            MyString(const MyString& source);

            // Destructor: Deallocates the memory that was previously reserved 
            // for this string.
            ~MyString();

            // Overloaded assignment operator to copy the content from one MyString to another.
            MyString& operator=(const MyString& right);

            // Overloaded [] operator to get the character at a specific index.
            char operator[](int index) const;

            // Overloaded [] operator to get/set the character at a specific index.
            char& operator[](int index);

            // Overloaded operators for comparing two MyString objects.
            friend bool operator<(const MyString& left, const MyString& right);
            friend bool operator<=(const MyString& left, const MyString& right);
            friend bool operator>(const MyString& left, const MyString& right);
            friend bool operator>=(const MyString& left, const MyString& right);
            friend bool operator==(const MyString& left, const MyString& right);
            friend bool operator!=(const MyString& left, const MyString& right);

            // Overloaded stream insertion operator to output the content of the MyString.
            friend std::ostream& operator<<(std::ostream& out, const MyString& source);

            // Returns the length of the c-string in this MyString.
            int length() const;
    };
}
