#include <iostream>
using namespace std;
#include <cstring>

class String
{
private:
    char *m;
    size_t s;

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
};

main()
{
    String s1("Lam");
    String s2("Dep trai");
    String s3 = s1 + s2;
//    String input;
//    String::getline(cin, input, '.');
//    cout << input << endl;
	cout << s1 << " " << s2 << " " << s3 << endl;
    cout << s1[2] << s3[5];
}