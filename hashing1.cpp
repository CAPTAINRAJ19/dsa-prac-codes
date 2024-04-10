// linear probing
#include <bits/stdc++.h>
using namespace std;

struct rec // a struct is a structure that consists of only data members and no member functions and by default the data members are public
{
    int roll;
    string name;
};

class hashing
{
    rec hashtable[10]; // creating a hashtable of size 10 where every block has (data members of struct rec)roll no and name

public:
    hashing() // here using a constructor we are assigning all the roll no values equal to -1
    {
        for (int i = 0; i < 10; i++)
        {
            hashtable[i].roll = -1;
        }
    }

    void insert(int roll1, string name1) // function for inserting the new entry in the hashtable
    {
        int x = roll1 % 10; // this is usefull for extracting the last digit of the number
        int u = 0;
        for (int i = 0; i < 10; i++) // for traversing the entire hashtable
        {
            if (hashtable[x % 10].roll == -1) //(hash function is mod by table size)if empty location is found out to be empty
            {
                hashtable[x % 10].roll = roll1;
                hashtable[x % 10].name = name1;
                u++;
                break;
            }
            x++;
        }
        if (u == 0) // this will happen if there is no empty location in the hashtable
        {
            cout << "no space \n";
        }
    }

    void search(int roll1) // function for searching a entry in the hashtable
    {
        int u = 0;
        int i = roll1 % 10;          // useful for extracting the last digit of the number
        for (int j = 0; j < 10; j++) // for traversing the entire hashtable
        {
            if (hashtable[i % 10].roll == roll1)
            {
                cout << "found : " << hashtable[i].name << endl;
                u++;
                break;
            }
            i++;
        }
        if (u == 0) // incase the entry is not found
        {
            cout << "Not found\n";
        }
    }

    void display() // simple function for displaying the contents of the hashtable
    {
        cout << "hashtable is as follows-:\n";
        for (int i = 0; i < 10; i++)
        {
            cout << hashtable[i].roll << " " << hashtable[i].name << endl;
        }
    }

    void deleteEntry(int roll1) // function for deleting an entry from the hashtable
    {
        int i = roll1 % 10;          // for extracting the last digit of the number
        for (int j = 0; j < 10; j++) // for traversing the entire length of the hashtable
        {
            if (hashtable[i % 10].roll == -1) // incase the entry is not found
            {
                cout << "empty\n";
                break;
            }
            else if (hashtable[i % 10].roll == -2) // this refers to the block whose element has been deleted
            {
                i++;
            }
            else if (hashtable[i % 10].roll == roll1)
            {
                hashtable[i % 10].roll = -2; // this shall indicate that the element is now deleted
                hashtable[i % 10].name = ""; // setting the name as default ""
                break;
            }
        }
    }
};
int main()
{
    hashing obj;
    int a;
    string b;
    cout << "Input the entries" << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> a >> b;
        obj.insert(a, b);
    }
    obj.display();
    cout << "Number of entries to be searched" << endl;
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cout << "Enter roll no to be searched\n";
        cin >> x;
        obj.search(x);
    }
    int k;
    cout << "Input the no of entries to be deleted" << endl;
    cin >> k;
    while (k--)
    {
        cout << "Enter roll no to be deleted\n";
        int y;
        cin >> y;
        obj.deleteEntry(y);
    }
    obj.display();
}
