#include <iostream>
#include <list>
#include <vector>

// Tag dispatching is a technique that enables us to SELECT one or another function overload at COMPILE TIME. 
// It is an alternative to std::enable_if and SFINAE and is simple to understand and use. 
// The term tag describes an empty class that has no members (data), or functions (behavior). 
// Such a class is only used to define a parameter (usually the last) of a function to decide 
// whether to select it at compile-time, depending on the supplied arguments.

struct RandomAccessContainerTag {};
struct ForwardAccessContainerTag {};

template <typename ContainerType>
typename ContainerType::reference GetNthElement(ContainerType container, size_t n, RandomAccessContainerTag)
{
    return container.at(n);
}

template <typename ContainerType>
typename ContainerType::reference GetNthElement(ContainerType container, size_t n, ForwardAccessContainerTag)
{
    auto iter = container.begin();
    for(int i=0; i<n; i++) 
        iter++;

    return *iter;
}


int main()
{
    std::vector<int> vec = {4,2,6,7,4,3,23,234};
    std::list<int> list = {2,6,5,22,33,12};

    auto i = GetNthElement(vec, 3, RandomAccessContainerTag{});
    auto j = GetNthElement(list, 3, ForwardAccessContainerTag{});

    std::cout << "i=" << i << std::endl;
    std::cout << "j=" << j << std::endl;

    return 0;
}