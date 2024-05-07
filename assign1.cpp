#include<bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    int rollNo;
};

class HashTable {
    vector<list<Student*>> table;
    int size;
    int hash(int rollNo) {
        return rollNo % size;
    }
public:
    HashTable(int size) : size(size) {
        table.resize(size);
    }
    void insert(Student* student) {
        int index = hash(student->rollNo);
        table[index].push_back(student);
    }
    Student* search(int rollNo, int& comparisons) {
        int index = hash(rollNo);
        for (Student* student : table[index]) {
            comparisons++;
            if (student->rollNo == rollNo) {
                return student;
            }
        }
        return nullptr;
    }
};

int main() {
    HashTable ht(10);
    ht.insert(new Student{"John Doe", 1});
    ht.insert(new Student{"Jane Doe", 11}); // collision with John Doe
    int comparisons = 0;
    Student* student = ht.search(11, comparisons);
    if (student != nullptr) {
        cout << "Found " << student->name << " after " << comparisons << " comparisons.\n";
    } else {
        cout << "Student not found after " << comparisons << " comparisons.\n";
    }
    return 0;
}