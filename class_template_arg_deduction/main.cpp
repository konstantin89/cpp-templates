#include <iostream>

template <typename T>
class MyClass
{
public:
    MyClass(T value): mValue(value)
    {

    }

private:
    T mValue;
};

int main()
{
/*
    a and b syntax is supported only from C++17.
    In lower C++ versions the following error will be printed:

    g++ -std=c++11 -Wall -Wextra main.cpp -o app
    main.cpp: In function ‘int main()’:
    main.cpp:18:13: error: missing template arguments before ‘a’
    18 |     MyClass a(20);
        |             ^
    main.cpp:19:13: error: missing template arguments before ‘b’
    19 |     MyClass b("HeyThere");
        |             ^
    make: *** [Makefile:7: app] Error 1
*/

    // Class template argument deduction allows us to create MyClass without explicit
    // template types declaration. 
    MyClass a(20);
    MyClass b("HeyThere");

    MyClass<int> c(21);
    MyClass<std::string> d("My String!");

    return 0;
}