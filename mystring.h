#include <iostream>

namespace cs_mystring {
    class MyString {
        private:
            char* cstring;
        public:
            MyString(const char* s = "");
            MyString(const MyString& source);
            ~MyString();
            MyString& operator=(const MyString& right);

            char operator[](int index) const;
            char& operator[](int index);

            friend bool operator<(const MyString& left, const MyString& right);
            friend bool operator<=(const MyString& left, const MyString& right);
            friend bool operator>(const MyString& left, const MyString& right);
            friend bool operator>=(const MyString& left, const MyString& right);
            friend bool operator==(const MyString& left, const MyString& right);
            friend bool operator!=(const MyString& left, const MyString& right);

            friend std::ostream& operator<<(std::ostream& out, const MyString& source);
            int length() const;
    };
}
