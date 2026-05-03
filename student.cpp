#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int roll;
    string name;
};
void addStudent() {
    ofstream file("students.txt", ios::app);

    Student s;
    cout << "Enter Roll Number: ";
    cin >> s.roll;
    cout << "Enter Name: ";
    cin >> s.name;

    file << s.roll << " " << s.name << endl;
    file.close();

    cout << "✅ Student added successfully!\n";
}
void displayStudents() {
    ifstream file("students.txt");

    Student s;
    cout << "\n--- Student Records ---\n";

    while (file >> s.roll >> s.name) {
        cout << "Roll: " << s.roll << " | Name: " << s.name << endl;
    }

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 3);

    return 0;
}