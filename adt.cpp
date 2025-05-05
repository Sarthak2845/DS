#include <iostream>
#include <list>
#include <string>
using namespace std;

const int SIZE = 10;  
class Dictionary {
    list<pair<string, string>> table[SIZE];  
    int hashFunction(string key) {
        int hash = 0;
        for (char c : key)
            hash += c; 
        return hash % SIZE; 
    }

public:
 
    void insert(string key, string value) {
        int index = hashFunction(key);

        for (auto& entry : table[index]) {
            if (entry.first == key) {
                entry.second = value; 
                return;
            }
        }
        table[index].push_back({key, value});
    }

    void find(string key) {
        int index = hashFunction(key);
        for (auto& entry : table[index]) {
            if (entry.first == key) {
                cout << "Value for key \"" << key << "\": " << entry.second << endl;
                return;
            }
        }
        cout << "Key \"" << key << "\" not found." << endl;
    }

    void deleteKey(string key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);  
                cout << "Key \"" << key << "\" deleted successfully." << endl;
                return;
            }
        }
        cout << "Key \"" << key << "\" not found." << endl;
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            if (!table[i].empty()) {
                cout << "Index " << i << ": ";
                for (auto& entry : table[i]) {
                    cout << "(" << entry.first << ", " << entry.second << ") ";
                }
                cout << endl;
            }
        }
    }
};

int main() {
    Dictionary dict;
    int choice;
    string key, value;

    do {
        cout << "\n1. Insert Key-Value Pair\n2. Find Key\n3. Delete Key\n4. Display Dictionary\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                dict.insert(key, value);
                break;
            case 2:
                cout << "Enter key to find: ";
                cin >> key;
                dict.find(key);
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                dict.deleteKey(key);
                break;
            case 4:
                dict.display();
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
