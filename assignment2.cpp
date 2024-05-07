// This program first reads words from a dictionary file and inserts them into a hash table.
// The dictionary file consists of a list of more than 100 correctly spelled lowercase words and meanings, separated by whitespace. The words are inserted into the hash table. Handle collision using separate chaining. After the reading of the dictionary file is complete, the program prompts the user for input. After input is obtained, each word that the user enters into the program is looked up within the hash table to see if it exists. If the user entered word exists within the hash table, then that word is displayed with meaning

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class HashTable
{
private:
    static const int TABLE_SIZE = 100;
    vector<vector<pair<string, string>>> table;

    // Hash function
    int hashFunction(const string &key)
    {
        int hash = 0;
        for (char c : key)
        {
            hash = (hash * 31 + c) % TABLE_SIZE;
        }
        return hash;
    }

public:
    HashTable() : table(TABLE_SIZE) {}

    // Insert a word and its meaning into the hash table
    void insert(const string &word, const string &meaning)
    {
        int index = hashFunction(word);
        table[index].push_back(make_pair(word, meaning));
    }

    // Search for a word in the hash table and return its meaning
    string search(const string &word)
    {
        int index = hashFunction(word);
        for (const auto &pair : table[index])
        {
            if (pair.first == word)
            {
                return pair.second;
            }
        }
        return "Meaning not found";
    }
};

int main()
{
    HashTable dictionary;

    // Read words and meanings from the dictionary file and insert into hash table
    ifstream file("dictionary.txt");
    if (!file)
    {
        cerr << "Error opening dictionary file." << endl;
        return 1;
    }

    string word, meaning;
    while (file >> word >> meaning)
    {
        dictionary.insert(word, meaning);
    }
    file.close();

    // Prompt user for input and look up words in the hash table
    cout << "Enter a word to get its meaning (Enter 'exit' to quit):" << endl;
    while (true)
    {
        string input;
        cin >> input;
        if (input == "exit")
        {
            break;
        }

        string wordMeaning = dictionary.search(input);
        cout << "Meaning of '" << input << "': " << wordMeaning << endl;
    }

    return 0;
}