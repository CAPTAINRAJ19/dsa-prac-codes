#include<bits/stdc++.h>

using namespace std;
struct Student {
    int rollNo;
    string name;
    string division;
    string address;
};

int main() {
    fstream file;
    file.open("student_data.txt");

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    int choice;
    do {
        cout << "1. Add student\n";
        cout << "2. Delete student\n";
        cout << "3. Insert student\n";
        cout << "4. Search student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Student student;
                cout << "Enter roll number: ";
                cin >> student.rollNo;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, student.name);
                cout << "Enter division: ";
                getline(cin, student.division);
                cout << "Enter address: ";
                getline(cin, student.address);

                file << student.rollNo << " " << student.name << " " << student.division << " " << student.address << endl;
                cout << "Student added successfully!" << endl;
                break;
            }
            case 2: {
                int rollNoToDelete;
                cout << "Enter roll number to delete: ";
                cin >> rollNoToDelete;

                fstream tempFile;
                tempFile.open("temp.txt", ios::out);

                int rollNo;
                string name, division, address;
                while (file >> rollNo >> name >> division >> address) {
                    if (rollNo != rollNoToDelete) {
                        tempFile << rollNo << " " << name << " " << division << " " << address << endl;
                    }
                }

                file.close();
                tempFile.close();

                remove("student_data.txt");
                rename("temp.txt", "student_data.txt");

                cout << "Student deleted successfully!" << endl;
                break;
            }
            case 3: {
                int position;
                cout << "Enter position to insert: ";
                cin >> position;

                fstream tempFile;
                tempFile.open("temp.txt");

                int rollNo;
                string name, division, address;
                int currentPosition = 1;
                while (file >> rollNo >> name >> division >> address) {
                    if (currentPosition == position) {
                        Student student;
                        cout << "Enter roll number: ";
                        cin >> student.rollNo;
                        cout << "Enter name: ";
                        cin.ignore();
                        getline(cin, student.name);
                        cout << "Enter division: ";
                        getline(cin, student.division);
                        cout << "Enter address: ";
                        getline(cin, student.address);

                        tempFile << student.rollNo << " " << student.name << " " << student.division << " " << student.address << endl;
                    }

                    tempFile << rollNo << " " << name << " " << division << " " << address << endl;
                    currentPosition++;
                }

                file.close();
                tempFile.close();

                remove("student_data.txt");
                rename("temp.txt", "student_data.txt");

                cout << "Student inserted successfully!" << endl;
                break;
            }
            case 4: {
                int rollNoToSearch;
                cout << "Enter roll number to search: ";
                cin >> rollNoToSearch;

                int rollNo;
                string name, division, address;
                bool found = false;
                while (file >> rollNo >> name >> division >> address) {
                    if (rollNo == rollNoToSearch) {
                        cout << "Roll No: " << rollNo << endl;
                        cout << "Name: " << name << endl;
                        cout << "Division: " << division << endl;
                        cout << "Address: " << address << endl;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Student not found!" << endl;
                }
                break;
            }
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    } while (choice != 5);

    file.close();

    return 0;
}