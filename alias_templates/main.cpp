#include <unordered_map>
#include <iostream>
#include <string>

//using alias allows us to define template aliases.
template <typename T> using IndexContainer = std::unordered_map<int, T>;

int main()
{
    IndexContainer<std::string> container;

    container[12] = "Content";
    container[4] = "what is this";

    std::cout << container[12] << std::endl;
}