#include <iostream>

template <typename T>
void Func(T value)
{
    std::cout << "Got value "<< value << " of type: " << typeid(value).name() << std::endl;
}

template <typename T>
class MyClass
{
public:
MyClass(T param): value(param)
{

}

void Method()
{
     // Non dependent type.
     // Func will be always called for type T.
    Func(value);
}

T value;
};

int main()
{
    // Program output:
    //
    // Got value 45 of type: i
    // Got value 3.2 of type: d
    // Got value 5 of type: i

    // Binding rules:
    // For dependent names, it is performed at the point of template INSTANTIATION. 
    // For non-dependent names, it is performed at the point of the template DEFINITION.

    MyClass c(3);
    c.value = 45.3;
    c.Method(); // Uses Func<int>

    Func(3.2);  // Uses Func<double>
    Func(5);    // Uses Func<int>

    return 0;
}