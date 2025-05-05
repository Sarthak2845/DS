#include <iostream>
#include <fstream>
using namespace std;
void addStudent() {
    ofstream fout("student.txt", ios::app);
    int roll;
    string name, division, address;
    cout << "Enter Roll No: ";
    cin >> roll;
    cout << "Enter Name (one word): ";
    cin >> name;
    cout << "Enter Division: ";
    cin >> division;
    cout << "Enter Address (one word): ";
    cin >> address;

    fout << roll << " " << name << " " << division << " " << address << endl;
    fout.close();
}
void displayStudent() {
    ifstream fin("student.txt");
    int roll, searchRoll;
    string name, division, address;
    bool found = false;

    cout << "Enter Roll No to search: ";
    cin >> searchRoll;
    while (fin >> roll >> name >> division >> address) {
        if (roll == searchRoll) {
            cout << "Roll: " << roll << "\nName: " << name
                 << "\nDivision: " << division << "\nAddress: " << address << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Student not found.\n";

    fin.close();
}
void deleteStudent() {
    ifstream fin("student.txt");
    ofstream fout("temp.txt");
    int roll, searchRoll;
    string name, division, address;
    bool found = false;

    cout << "Enter Roll No. to delete: ";
    cin >> searchRoll;

    while (fin >> roll >> name >> division >> address) {
        if (roll == searchRoll) {
            found = true;
            continue; // skip writing
        }
        fout << roll << " " << name << " " << division << " " << address << endl;
    }

    fin.close();
    fout.close();
    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found)
        cout << "Record deleted.\n";
    else
        cout << "Student not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Student\n2. Display Student\n3. Delete Student\n4. Exit\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
            addStudent();
        else if (choice == 2)
            displayStudent();
        else if (choice == 3)
            deleteStudent();

    } while (choice != 4);

    return 0;
}
