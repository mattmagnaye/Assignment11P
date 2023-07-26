#include "mystring.h"
#include <cstring>

namespace cs_mystring {

    MyString::MyString(const char* s) {
        cstring = new char[strlen(s) + 1];
        strcpy(cstring, s);
    }

    MyString::MyString(const MyString& source) {
        cstring = new char[strlen(source.cstring) + 1];
        strcpy(cstring, source.cstring);
    }

    MyString::~MyString() {
        delete[] cstring;
    }

    MyString& MyString::operator=(const MyString& right) {
        if (this != &right) {
            delete[] cstring;
            cstring = new char[strlen(right.cstring) + 1];
            strcpy(cstring, right.cstring);
        }
        return *this;
    }

    char MyString::operator[](int index) const {
        return cstring[index];
    }

    char& MyString::operator[](int index) {
        return cstring[index];
    }

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

    std::ostream& operator<<(std::ostream& out, const MyString& source) {
        out << source.cstring;
        return out;
    }

    int MyString::length() const {
        return strlen(cstring);
    }
}
