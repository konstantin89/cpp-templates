#include <iostream>
#include <type_traits>

int main() 
{
    using i = std::integral_constant<int, 2>;
    std::cout << i::value << std::endl;
    
    using j = std::integral_constant<i::value_type, 3>;
    std::cout << j::value << std::endl;

    return 0;
}