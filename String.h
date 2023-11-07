#include <iostream>
using namespace std;
#include <algorithm>
#include <cstring>

class String
{
private:
    char *m;
    size_t s;
    size_t max;

public:
    String() : m(new char[1]), s(0)
    {
        *m = '\0';
    }

    String(const char *str) : s(strlen(str))
    {
        m = new char[s + 1];
        strcpy(m, str);
    }

    String(const String &other) : s(other.s)
    {
        m = new char[s + 1];
        strcpy(m, other.m);
    }

    ~String()
    {
        delete[] m;
    }

    void push_back(char c)
    {
        if (s + 1 >= max)
        {
            max = s + 1;
            char *tmp = new char[max];
            strcpy(tmp, m);
            delete[] m;
            m = tmp;
        }
        m[s] = c;
        m[s + 1] = '\0';
        ++s;
    }

    String &operator=(const String &other)
    {
        if (this != &other)
        {
            delete[] m;
            s = other.s;
            m = new char[s + 1];
            strcpy(m, other.m);
        }
        return *this;
    }

    size_t size() const
    {
        return s;
    }
    // template<typename T>
    String operator+(const String &other) const
    {
        String newString;
        newString.s = s + other.s;
        delete[] newString.m;
        newString.m = new char[newString.s + 1];
        strcpy(newString.m, m);
        strcat(newString.m, other.m);
        return newString;
    }

    const char &operator[](size_t index) const
    {
        return m[index];
    }

    friend ostream &operator<<(ostream &o, const String &str)
    {
        o << str.m;
        return o;
    }

    static void getline(istream &i, String &str, char delim)
    {
        char buffer[256];
        i.getline(buffer, 256, delim);
        str = buffer;
    }

    static String tostring(int num)
    {
        String result;
        bool isNegative = false; //check so am
        if (num < 0)
        {
            isNegative = true;
            num = -num;
        }
        if (num == 0)   return "0";
        while (num > 0)
        {
            char digit = '0' + (num % 10); // chuyen so thanh ky tu tuong ung
            result.push_back(digit);       
            num /= 10;
        }
        if (isNegative) result.push_back('-'); //them dau am vao cuoi chuoi neu la so am
        reverse(result.m, result.m + result.size()); //dao nguoc chuoi de dung thu tu
        return result;
    }

    static int toint(const String &s)
    {
        int result = 0;
        int sign = 1;
        int i = 0;
        if (s[0] == '-')
        {
            sign = -1;
            i = 1;
        }
        for (; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                result = result * 10 + (s[i] - '0');
            else
            {
                // exception cho ni
            }
        }
        return result * sign;
    }
};

main()
{
    // Test constructors
    String s1; // String()
    String s2("Hello, world!"); // String(const char* str)

    // Test operator<<
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    // Test push_back
    s1.push_back('H');
    s1.push_back('i');
    s1.push_back('!');
    cout << "s1 sau push_back: " << s1 << endl;

    // Test operator+
    String s3 = s1 + s2;
    cout << "s3 = s1 + s2 = " << s3 << endl;

    // Test size
    cout << "Size of s3: " << s3.size() << endl;

    // Test getline
    cout << "Nhap chuoi: ";
    String s4;
    String::getline(cin, s4, '.');
    cout << "s4: " << s4 << endl;

    // Test tostring
    int num = -12345;
    String s5 = String::tostring(num);
    cout << "s5: " << s5 << endl;

    // Test toint
    String s6 = "6789";
    int num2 = String::toint(s6);
    cout << "s6: " << s6 << endl;
}
