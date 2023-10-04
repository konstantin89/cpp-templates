#include <iostream>

// When T&& used in templates, it can be rvalue or lvalue reference.
// 
template <typename T>
void f(T&& value) // Forwarding reference parameter
{
    std::cout << "Forwarding reference f" << std::endl;
}

template <typename T>
void g(T const && value) // rvalue reference parameter
{
    std::cout << "rvalue reference f" << std::endl;
}

void h(int &&value) // rvalue reference parameter
{
    std::cout << "rvalue reference h" << std::endl;
}

int main()
{
    int x=0;
    int &y = x;

    f(x); // lvalue reference parameter
    f(y); // lvalue reference parameter
    f(std::move(x)); //rvalue reference parameter

    int i = 2;
    // The following line is failing because g accepts rvalue reference.
    // g(i); // Error - error: cannot bind rvalue reference of type ‘const int&&’ to lvalue of type ‘int’

    g(std::move(i)); //rvalue reference parameter

    int j = 3;
    h(std::move(j)); // rvalue reference parameter

    return 0;
}
