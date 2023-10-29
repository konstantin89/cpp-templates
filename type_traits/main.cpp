#include <iostream>
#include <type_traits>
class CopyConstructibleClass
{
public:
    // Constructor
    CopyConstructibleClass(int value): mValue(value)
    {

    }

    // 1 - Destructor
    ~CopyConstructibleClass() 
    {

    }

    // 2 - Copy Constructor
    CopyConstructibleClass(const CopyConstructibleClass& other) noexcept
    {
        mValue = other.mValue;
    }

    // 3 - Copy Assignment Operator
    CopyConstructibleClass& operator=(const CopyConstructibleClass& other) noexcept
    {
        mValue = other.mValue;
        return *this;
    }

    // 4 - Move Constructor
    CopyConstructibleClass(CopyConstructibleClass&& other) noexcept = delete;

    // 5 - Move Assignment Operator
    CopyConstructibleClass& operator=(CopyConstructibleClass&& other) noexcept = delete;

private:
    int mValue;
};

int main()
{
    std::cout << "CopyConstructibleClass is_copy_constructible = " 
              << std::is_copy_constructible<CopyConstructibleClass>::value << std::endl;

    std::cout << "CopyConstructibleClass is_trivially_copy_constructible = " 
              << std::is_trivially_copy_constructible<CopyConstructibleClass>::value << std::endl;

    std::cout << "CopyConstructibleClass is_nothrow_copy_constructible = " 
              << std::is_nothrow_copy_constructible<CopyConstructibleClass>::value << std::endl;

    return 0;
}