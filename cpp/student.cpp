#include <iostream>
#include <vector>
#include <fstream>

class Student
{
    std::string m_firstName = "First Name";
    std::string m_lastName = "Last Name";
    int m_id = 0;
    float m_avg = 0;
public:
    Student() {}
    Student(std::string firstName, std::string lastName, int id, float avg)
    : m_firstName(firstName)
    , m_lastName(lastName)
    , m_id(id)
    , m_avg(avg) // initializer list
    {}

    float getAvg() const
    {
        return m_avg;
    }
    int getID() const
    {
        return m_id;
    }
    std::string getFullName() const
    {
        return m_firstName + " " + m_lastName;
    }
    void print() const
    {
        std::cout << getFullName() << " " << m_id << " " << m_avg << std::endl;
    }
};

class Course
{
    std::string m_name = "Course Name";
    std::vector<Student> m_students;
public:
    Course() {}
    Course(std::string name)
    : m_name(name)
    {}

    void addStudent(const Student& student)
    {
        m_students.push_back(student);
    }

    // const correctness:
    // *const std::vector<Student>& getStudents(), returned value cannot be mutated
    // *getStudents() const, function will not change any class members
    // *addStudent(const Student& student), addStudent fn cannot mutate student arg

    const std::vector<Student>& getStudents() const
    {
        return m_students;
    }

    void print() const
    {
        std::cout << m_name << ":" << std::endl;
        // size_t is used to represent the size of an object
        // for(size_t i = 0; i < m_students.size(); i++)
        // {
        //     m_students[i].print();
        // }

        // range based for loop
        // *auto x = initializer, deduces the type of x from the type of initializer
            // *(the same way as template type deduction works for function template)
        for(const auto& student: m_students)
        {
            student.print();
        }
    }

    // *relative or absolute path to file
    void loadFromFile(const std::string& pathTOFile)
    {
        std::ifstream fin(pathTOFile);
        std::string first, last;
        int id;
        float avg;
        while (fin >> first)
        {
            // cpp file stream will infer types and throws an err if there's a mismatch? or will cast?
            fin >> last >> id >> avg;
            addStudent(Student(first, last, id, avg));
        }
    }
};

// passing cmd arguments
// int argc, argument count, plus 1, the name of the program will be prepended to the array i.e argv[0] == program name e.g 'g++.exe'
// char * argv[] || char** argv, argument vector, can loop through argv based on argc (i < argc) in main()

int main(int argc, char * argv[])
{
    // ?100.24 is casted to int 100... how? and why?
    Student bob("Bod", "Billy", 100.24, 2.34f); // direct initialization
    Student jimmy = Student("John", "Smith", 101, 2.78f); // copy initialization

    // e.g if Student::print() is not "print() const {}" compiler will err, will refer that 'print() {}' will mutate Student members
        // 'discards qualifiers', 'discarding the constness of this'
    // const Student james(); // compiler will interpret james() as a function declaration not default Student () constructor
    // const Student momo; default constructor

    Course cpp101("CPP 101");

    cpp101.addStudent(bob);
    cpp101.addStudent(jimmy);

    cpp101.print();

    cpp101.loadFromFile("students.txt");
    cpp101.print();

    std::cin.get();
    return 0;
}