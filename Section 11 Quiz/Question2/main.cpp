/*
 * Write the following program: Create a struct that holds a student’s first name and grade (on a scale of 0-100).
 *
 * Ask the user how many students they want to enter.
 *
 * Create a std::vector to hold all of the students.
 * Then prompt the user for each name and grade.
 *
 * Once the user has entered all the names and grade pairs, sort the list by grade (highest first).
 * Then print all the names and grades in sorted order.
 */

#include <iostream>
#include <vector>
struct Student {
    std::string first_name;
    int grade;
};

bool compareStudentGrades(Student a, Student b) {
    return a.grade > b.grade;
}

int main() {
    std::cout << "How many students would you like to enter? >> ";
    int num_students {};
    std::cin >> num_students;

    std::vector<Student> students;

    for (int i {0}; i < num_students; ++i) {
        std::cout << "Student #" << i + 1 << '\n';

        std::cout << "Name >> ";
        std::string name {};
        std::getline(std::cin >> std::ws, name);

        bool entering_grade {true};
        int grade {0};
        while (entering_grade) {
            std::cout << "Grade (0-100) >> ";
            std::cin >> grade;

            if ((grade > 100) || (grade < 0)) {
                std::cout << ">> Grade must be between 0-100!" << '\n';
            } else {
                entering_grade = false;
            }
        }

        Student temp_student {name, grade};
        students.push_back(temp_student);
    }

    std::sort(students.begin(), students.end(), compareStudentGrades);

    std::cout << '\n';
    for (Student s : students) {
        std::cout << s.first_name << " got a grade of " << s.grade << '\n';
    }

    return 0;
}
