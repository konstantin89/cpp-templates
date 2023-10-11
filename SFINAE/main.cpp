#include <iostream>

/////////////////////////// Define classes ///////////////////////////////
class ClassA
{
public:
    void print() const
    {
        std::cout << "print method is called" << std::endl;
    }
};

class ClassB
{
public:
    // No print method
};

/////////////////////////// Define the type trait ///////////////////////////////
template <typename T>
struct is_supporting_print
{
    static constexpr bool value = false;
};

template <>
struct is_supporting_print<ClassA>
{
    static constexpr bool value = true;
};

// Define shortcut type:
// Instead of using is_supporting_print<T>::value
// we write is_supporting_print_v<T>
template <typename T>
inline constexpr bool is_supporting_print_v = is_supporting_print<T>::value;

/////////////////////////// Define template function ///////////////////////////////
template <typename T>
void LogClass(const T& instance)
{
    // compile type if. From C++17
    if constexpr(is_supporting_print_v<T>)
    {
        instance.print();
    }
    else
    {
        std::cout << "doesn't supports print method" << std::endl;
    }
}

int main()
{
    ClassA a;
    ClassB b;

    LogClass(a);
    LogClass(b);

    return 0;
}