# GPA Calculator

The GPA Calculator is a C++ program that computes a student's Cumulative Grade Point Average (CGPA) based on their exam results. It allows you to input the number of courses taken, the grades received, and the credit hours for each course. The program then calculates the GPA for each semester and the overall CGPA.

## Features

- Input the number of semesters.
- Input the number of courses for each semester.
- Input the course name, grade, and credit hours for each course.
- Calculate the GPA for each semester.
- Calculate the cumulative GPA (CGPA) based on all semesters.
- Display the GPA for each semester and the final CGPA.

## Usage

1. Compile the program using a C++ compiler.
2. Run the compiled executable.
3. Follow the on-screen prompts to input the number of semesters and course details.
4. View the GPA for each semester and the final CGPA.

## Sample Input/Output

    Enter the number of semesters: 2

    Enter the number of courses for semester 1: 3
    Enter the name of course 1: Math
    Enter the grade for course 1: 3.7
    Enter the credit hours for course 1: 3
    Enter the name of course 2: Physics
    Enter the grade for course 2: 3.5
    Enter the credit hours for course 2: 4
    Enter the name of course 3: Chemistry
    Enter the grade for course 3: 4.0
    Enter the credit hours for course 3: 3

    GPA for semester 1: 3.7

    Enter the number of courses for semester 2: 2
    Enter the name of course 1: Biology
    Enter the grade for course 1: 3.3
    Enter the credit hours for course 1: 3
    Enter the name of course 2: English
    Enter the grade for course 2: 3.8
    Enter the credit hours for course 2: 3

    GPA for semester 2: 3.55

    Cumulative GPA (CGPA): 3.625

## Implementation Details:

The program is implemented in C++ and uses a class to store course details and a function to calculate the GPA for each semester. The CGPA is calculated based on the cumulative grade points and credit hours from all semesters.

### Class Definition

    Class Course {
    public:
        string name;
        float grade;
        int creditHours;
    };


## GPA Calculation function:
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

## Main Function:

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
