#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

float getGradePoint(char grade)
{
    switch(toupper(grade))
    {
        case 'A': return 4.0;
        case 'B': return 3.0;
        case 'C': return 2.0;
        case 'D': return 1.0;
        default: return 0.0;
    }
}

int main()
{
    int semesters;

    cout << "Enter number of semesters: ";
    cin >> semesters;

    double overallGradePoints = 0;
    int overallCredits = 0;

    for(int sem = 1; sem <= semesters; sem++)
    {
        int courses;

        cout << "\n===== Semester " << sem << " =====\n";
        cout << "Enter number of courses: ";
        cin >> courses;

        double semesterGradePoints = 0;
        int semesterCredits = 0;

        vector<char> grades(courses);
        vector<int> credits(courses);

        for(int i = 0; i < courses; i++)
        {
            cout << "\nCourse " << i + 1 << endl;

            cout << "Enter grade (A/B/C/D/F): ";
            cin >> grades[i];

            cout << "Enter credit hours: ";
            cin >> credits[i];

            float gradePoint = getGradePoint(grades[i]);

            semesterGradePoints += gradePoint * credits[i];
            semesterCredits += credits[i];
        }

        double semesterGPA = semesterGradePoints / semesterCredits;

        cout << "\nCourse Details:\n";
        for(int i = 0; i < courses; i++)
        {
            cout << "Course " << i + 1
                 << " | Grade: " << grades[i]
                 << " | Credits: " << credits[i]
                 << endl;
        }

        cout << fixed << setprecision(2);
        cout << "\nSemester GPA: " << semesterGPA << endl;

        overallGradePoints += semesterGradePoints;
        overallCredits += semesterCredits;
    }

    double cgpa = overallGradePoints / overallCredits;

    cout << "\n================================";
    cout << "\nOverall CGPA: " << fixed << setprecision(2) << cgpa;
    cout << "\n================================\n";

    return 0;
}
