#include <iostream>
#include <list>
using namespace std;

const int SIZE = 10;
class HashTable
{
    list<pair<string, string>> table[SIZE];

    int hashFunction(string key)
    {
        int hash = 0;
        for (char c : key)
            hash += c;
        return hash % SIZE;
    }

public:
    void insert(string name, string number)
    {
        int index = hashFunction(name);
        table[index].push_back({name, number});
    }

    void search(string name)
    {
        int index = hashFunction(name);
        for (auto entry : table[index])
        {
            if (entry.first == name)
            {
                cout << "Number: " << entry.second << endl;
                return;
            }
        }
        cout << "Client not found.\n";
    }
};

int main()
{
    HashTable phoneBook;
    int n;
    string name, number;

    cout << "Enter number of clients: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter number: ";
        cin >> number;
        phoneBook.insert(name, number);
    }

    cout << "\nEnter name to search: ";
    cin >> name;
    phoneBook.search(name);

    return 0;
}
