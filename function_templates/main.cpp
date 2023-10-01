#include <iostream>

class Student
{
public:
    Student(int grade) : grade(grade){ }
    int GetGrade() { return grade; }

    bool operator<(const Student& other) const 
    {
        return grade < other.grade;
    }

private:
    int grade;
};

// Note - For historical instead of <typename T> we can use <class T>
template <typename T>
T max(T a, T b)
{
    return a < b ? b : a;
}

void maxExamples()
{
    // Note - ::max ensures that we use the max from global namespace and not std::max.
    std::cout << "max(4,5) = " << ::max(4,5) << std::endl;
    std::cout << "max(4.5,4.7) = " << ::max(4.5,4.7) << std::endl;

    Student s1(89);
    Student s2(92);
    std::cout << "max(Student(89), Student(92)) = " << ::max(s1, s2).GetGrade() << std::endl;

    //std::cout << "max(4, 4.7) = " << ::max(4, 4.7) << std::endl;                      // Compilation error - can't deduce type
    std::cout << "max<double>(4, 4.7) = " << ::max<double>(4, 4.7) << std::endl;        // Solves the compilation error
}

int main()
{
    maxExamples();

    return 0;
}