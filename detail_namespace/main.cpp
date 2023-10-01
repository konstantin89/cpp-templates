/*
    Brief
    =====

    Since C++ templates are header only implementations, its hard to hide private implementation 
    details from user.
    To hide private implementation details from user we can declare detail namespace and use
    it to store private implementation details.
*/

#include <iostream>

// Declare a namespace for private implementation details.
// This is private implementations namespace that used to prevent user
// accessing private code in templates.
namespace detail 
{
    template <typename U>
    void _print(U value) 
    {
        std::cout << value << std::endl;
    }
}

// Public interface of the template class
template <typename T>
class MyTemplate 
{
public:
    MyTemplate(T value) : data(value) 
    {

    }

    // Wrapper function to access the private function
    void Print() 
    {
        detail::_print(data);
    }

private:
    T data;
};

int main()
{
    MyTemplate<int> instance(42);
    instance.Print();  

    return 0;
}