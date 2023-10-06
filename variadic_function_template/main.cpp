#include <iostream>

template <typename T>
T min(T a, T b)
{
    return (a<b) ? a : b;
}

template <typename T, typename... Args>
T min(T a, Args... args)
{
    return min(a, min(args...));
}

// If using the -O flag, the following ASM code is generated.
// Note that the compiler uses constant 7 as min value without any function template generation.

// int main(int argc, char **argv, char **envp);
// 0x000106d0      push    {r4, lr}
// 0x000106d4      ldr     r1, [str.min_41__35__23__7__10__576] ; 0x106f4
// 0x000106d8      ldr     r0, [std::cout] ; 0x106f8
// 0x000106dc      bl      imp.std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(bl      0x10598 ; method.std::basic_ostream_char__std::char_traits_char_____std.operator____std::char_traits_char____std::basic_ostream_char__std::char_traits_char______char_const ;  method.std::basic_ostream_char__std::char_traits_char_____std.operator____std::char_traits_char____std::basic_ostream_char__std::char_traits_char______char_const(void)
// 0x000106e0      mov     r1, 7
// 0x000106e4      bl      imp.std::ostream::operator<<(int) ; method.std::ostream.operator___int ;  method.std::ostream.operator___int(void)
// 0x000106e8      bl      imp.std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(l      0x10580 ; method.std::basic_ostream_char__std::char_traits_char_____std.endl_char__std::char_traits_char____std::basic_ostream_char__std::char_traits_char ;  method.std::basic_ostream_char__std::char_traits_char_____std.endl_char__std::char_traits_char____std::basic_ostream_char__std::char_traits_char(void)
// 0x000106ec      mov     r0, 0
// 0x000106f0      pop     {r4, pc}

int main()
{
    std::cout << "min(41, 35, 23, 7, 10, 576) = " << min(41, 35, 23, 7, 10, 576) << std::endl;

    return 0;
}