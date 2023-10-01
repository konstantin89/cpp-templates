#include <iostream>
#include <cstring>

namespace my_lib
{

// Template params can be data types as well, not only types.
// Here buffer size is a template.
template <typename DataType, size_t Size>
class Buffer
{
private:

public:
    Buffer()
    {
        memset(mBuffer, 0, sizeof(mBuffer));
    }

    DataType* Data() const
    {
        return mBuffer;
    }

    size_t GetSize() const
    {
        return Size;
    }

    constexpr DataType& operator[](size_t index)
    {
        return mBuffer[index];
    }

private:
    DataType mBuffer[Size];
};

} //namespace my_lib

int main()
{
    my_lib::Buffer<int, 32> buf;

    std::cout << "Buffer object size: " << sizeof(buf) << std::endl;

    buf[3] = 15;
    std::cout << "buf[3]: " << buf[3] << std::endl;

    return 0;
}