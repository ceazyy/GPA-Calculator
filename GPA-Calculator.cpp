#include <bits/stdc++.h>

using namespace std;

class Course {
public:
    string name;
    float grade;
    int creditHours;
};

float calculateGPA(vector<Course> courses) {
    float totalGradePoints = 0;
    int totalCreditHours = 0;

    for (const auto& course : courses) {
        totalGradePoints += course.grade * course.creditHours;
        totalCreditHours += course.creditHours;
    }

    if (totalCreditHours == 0) return 0;
    return totalGradePoints / totalCreditHours;
}

int main() {
    int numSemesters;
    cout << "Enter the number of semesters: ";
    cin >> numSemesters;

    float cumulativeGPA = 0;
    int cumulativeCreditHours = 0;

    for (int i = 0; i < numSemesters; ++i) {
        int numCourses;
        cout << "\nEnter the number of courses for semester " << i + 1 << ": ";
        cin >> numCourses;

        vector<Course> courses(numCourses);

        for (int j = 0; j < numCourses; ++j) {
            cout << "Enter the name of course " << j + 1 << ": ";
            cin >> courses[j].name;
            cout << "Enter the grade for course " << j + 1 << ": ";
            cin >> courses[j].grade;
            cout << "Enter the credit hours for course " << j + 1 << ": ";
            cin >> courses[j].creditHours;
        }

        float semesterGPA = calculateGPA(courses);
        cout << "GPA for semester " << i + 1 << ": " << semesterGPA << endl;

        for (const auto& course : courses) {
            cumulativeGPA += course.grade * course.creditHours;
            cumulativeCreditHours += course.creditHours;
        }
    }

    if (cumulativeCreditHours == 0) {
        cout << "No courses taken, CGPA cannot be calculated." << endl;
    } else {
        float CGPA = cumulativeGPA / cumulativeCreditHours;
        cout << "\nCumulative GPA (CGPA): " << CGPA << endl;
    }

    return 0;
}
