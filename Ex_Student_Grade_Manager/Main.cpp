#include <iostream>
#include <string>

using namespace std;

//creating struct
struct Student {
    string name;
    int id;
    double* grades; //pointer to the grades in memory
};

//grade validation
bool isInRange(double grade) {
    return (grade >= 0 && grade <= 100);
}

int main() {
    //creating arrays
    int numStudents;
    int numSubjects; 
    cout << "Enter the number of students: ";
    cin >> numStudents;
    cout << "Enter the number of subjects: ";
    cin >> numSubjects;
    Student* students = new Student[numStudents]; //allocating student array 


    //Filling properties of students
    for (int i = 0; i < numStudents; ++i) {
        //filling properties of students array
        cout << "Enter data for student #" << i + 1 << ":\n";
        cout << "Name: ";
        cin >> students[i].name;
        cout << "ID: ";
        cin >> students[i].id;

        //allocating array for grades
        students[i].grades = new double[numSubjects];

        //filling properties of subjects array
        for (int a = 0; a < numSubjects; ++a) {
            double grade;

            do {
                cout << "Enter grade #" << a + 1 << " (0-100): ";
                cin >> grade;
                if (!isInRange(grade)) {
                    cout << "Please enter a grade between 0 and 100!\n";
                }
            } while (!isInRange(grade));

            students[i].grades[a] = grade; 
        }
    }

    //Display
    cout << "Students data:\n";
    for (int i = 0; i < numStudents; ++i) {

        cout << "Name: " << students[i].name << ", ID: " << students[i].id << ", Grades: ";//line continues in for loop
        for (int a = 0; a < numSubjects; ++a) {

            cout << students[i].grades[a]; //cout grades
            if (a < numSubjects - 1) {     //cout comma after each grade (not last).
                cout << ", ";
            }
        }
        cout << endl;
    }

    //freeing memory for grades 
    for (int i = 0; i < numStudents; ++i) {
        delete[] students[i].grades;
    }
    //freeing memory of array
    delete[] students;

    return 0;
}