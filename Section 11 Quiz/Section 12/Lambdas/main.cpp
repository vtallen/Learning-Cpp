/*
 * [ captureClause ] ( parameters ) -> returnType
{
    statements;
}

 Create a struct Student that stores the name and points of a student.

 Create an array of students and use std::max_element to find the student with the most points,
 then print that student’s name. std::max_element takes the begin and end of a list,
 and a function that takes 2 parameters and returns true if the first argument is less than the second.
 */

#include <iostream>
#include <array>

struct Student {
    std::string name;
    int points;
};

struct Season {
    std::string_view name{};
    double averageTemperature{};
};

int main() {
    std::array<Student, 8> arr{
            {{"Albert", 3},
             {"Ben", 5},
             {"Christine", 2},
             {"Dan", 8}, // Dan has the most points (8).
             {"Enchilada", 4},
             {"Francis", 1},
             {"Greg", 3},
             {"Hagrid", 5}}
    };

    const auto student_with_most_points{std::max_element(arr.begin(), arr.end(),
                                                         [](Student s, Student t) {
                                                             return s.points < t.points;
                                                         })};
    std::cout << student_with_most_points->name << " is the best student\n";

    // ===================================================================================================

    /*
    * Use std::sort here
    * Use std::sort and a lambda in the following code to sort the seasons by ascending average temperature.
    */

    std::array<Season, 4> seasons{
            {{"Spring", 285.0},
             {"Summer", 296.0},
             {"Fall", 288.0},
             {"Winter", 263.0}}
    };

    std::sort(seasons.begin(), seasons.end(), [](Season s, Season t) {
        return t.averageTemperature > s.averageTemperature;
    });

    for (const auto &season: seasons) {
        std::cout << season.name << '\n';
    }
    return 0;
}
