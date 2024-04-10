//linear probing with chaining
#include <bits/stdc++.h>
using namespace std;

struct rec      //this is a structure that has two data members(columns of the hashtable are here)
{
    int roll;
    int chain;
};

class hashing
{
    rec hashtable[10];//creating a hashtable of size 10

public:
    hashing()
    {
        for (int i = 0; i < 10; i++)//this is a constructor that is initializing all the entries to -1
        {
            hashtable[i].roll = -1;
            hashtable[i].chain = -1;
        }
    }

    void insert(int roll1)//function for inserting a new entry
    {
        int x = roll1 % 10;//useful for extracting the last digit of number
        int u = 0;
        int y = x;
        while (1)//infinite loop
        {
            if (u > 0)
            {
                break;
            }
            if (hashtable[x].roll == -1)//if empty location is found then enter the element in this position
            {
                hashtable[x].roll = roll1;
                u++;
                break;
            }
            else if ((hashtable[x].roll) % 10 == y && hashtable[x].chain == -1)//if this position is occupied by an element of the same hash value and chain has not been started
            {
                for (int i = x; i <= x + 10; i++)//entering the value in next empty location and updating the chain of that hash value
                {
                    if (hashtable[i % 10].roll == -1)
                    {
                        hashtable[i % 10].roll = roll1;
                        hashtable[x].chain = i % 10;//updating the chain
                        u++;
                        break;
                    }
                }
            }
            else//if an element of different hashvalue is found in the block
            {
                if (u > 0)
                {
                    break;
                }
                for (int i = x; i <= x + 10; i++)
                {
                    if (u > 0)
                    {
                        break;
                    }
                    int w = i;
                    if (hashtable[w % 10].roll == -1)//searching immediately next empty spot in the hashtable
                    {
                        hashtable[w % 10].roll = roll1;
                        hashtable[w % 10].chain = -1;
                        u++;
                        break;
                    }
                    else if (hashtable[w % 10].roll % 10 == y)//incase while searching in the table we come across a element of same hashvalue
                    {
                        if (u > 0)
                        {
                            break;
                        }
                        if (hashtable[w % 10].chain == -1)//incase the element found was the only element of the hashvalue that we wanted to enter and no follow up chain existed
                        {
                            for (int j = w; j <= w + 10; j++)//finding the immediate next location (empty) and updating chain after insertion
                            {
                                if (hashtable[j % 10].roll == -1)
                                {
                                    hashtable[j % 10].roll = roll1;
                                    hashtable[w % 10].chain = j % 10;
                                    u++;
                                    break;
                                }
                            }
                        }
                        else//incase follow up chain existed in the hashtable
                        {
                            while (hashtable[w].chain != -1)//finding the last element of the chain
                            {
                                w = hashtable[w].chain;
                            }
                            for (int j = w; j <= w + 10; j++)//making insertion in the immediate next empty block
                            {
                                if (hashtable[j % 10].roll == -1)
                                {
                                    hashtable[j % 10].roll = roll1;
                                    hashtable[w % 10].chain = j % 10;
                                    u++;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    void search(int roll1)
    {
        int u = 0;
        int i = roll1 % 10;
        while (1)
        {
            if (hashtable[i].roll == roll1)
            {
                cout << "Element is found : " << hashtable[i].roll << endl;
                u++;
                break;
            }
            i = hashtable[i].chain;
            if (u > 0)
            {
                break;
            }
        }
        if (u == 0)
        {
            cout << "Not found\n";
        }
    }

    void display()
    {
        cout << "Hashtable is as follows:\n";
        for (int i = 0; i < 10; i++)
        {
            cout << hashtable[i].roll << " " << hashtable[i].chain << endl;
        }
    }

    void deleteEntry(int roll1)
    {
        int i = roll1 % 10;
        for (int j = 0; j < 10; j++)
        {
            if (hashtable[i % 10].roll == -1)
            {
                cout << "empty\n";
                break;
            }
            else if (hashtable[i % 10].roll == -2)
            {
                i++;
            }
            else if (hashtable[i % 10].roll == roll1)
            {
                hashtable[i % 10].roll = -2;
                break;
            }
        }
    }
};
int main()
{
    hashing obj;
    int a;
    cout << "Input the entries" << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> a;
        obj.insert(a);
    }
    obj.display();
    int n;
    cout << "Input the number of elements to be searched" << endl;
    cin >> n;
    while (n--)
    {
        int x;
        cout << "Enter the roll number to be searched\n";
        cin >> x;
        obj.search(x);
    }
    int k;
    cout << "Input the number of elements to be deleted" << endl;
    cin >> k;
    while (k--)
    {
        cout << "Enter the roll number to be deleted\n";
        int y;
        cin >> y;
        obj.deleteEntry(y);
    }
    obj.display();
}
