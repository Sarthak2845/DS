#include <iostream>
#include <string>
using namespace std;
struct Node
{
    string name;
    int count;
    Node *children[10];
};

class BookTree
{
    Node *root;

public:
    BookTree()
    {
        root = NULL;
    }
    void create()
    {
        root = new Node;
        cout << "Enter book name: ";
        cin >> root->name;
        cout << "Enter number of chapters: ";
        cin >> root->count;
        for (int i = 0; i < root->count; i++)
        {
            root->children[i] = new Node;
            cout << "Enter chapter " << i + 1 << " name: ";
            cin >> root->children[i]->name;
            cout << "Enter number of sections in chapter " << i + 1 << ": ";
            cin >> root->children[i]->count;
            for (int j = 0; j < root->children[i]->count; j++)
            {
                root->children[i]->children[j] = new Node;
                cout << "Enter section " << j + 1 << " name: ";
                cin >> root->children[i]->children[j]->name;
                cout << "Enter number of subsections in section " << j + 1 << ": ";
                cin >> root->children[i]->children[j]->count;
                for (int k = 0; k < root->children[i]->children[j]->count; k++)
                {
                    root->children[i]->children[j]->children[k] = new Node;
                    cout << "Enter subsection " << k + 1 << " name: ";
                    cin >> root->children[i]->children[j]->children[k]->name;
                }
            }
        }
    }
    void display()
    {
        if (!root)
            return;
        cout << "\nBook Name:" << root->name << endl;
        for (int i = 0; i < root->count; i++)
        {
            cout << "\tChapter " << i + 1 << ": " << root->children[i]->name << endl;
            for (int j = 0; j < root->children[i]->count; j++)
            {
                cout << "\t\tSection " << j + 1 << ": " << root->children[i]->children[j]->name << endl;
            }
            for (int j = 0; j < root->children[i]->count; j++)
            {
                cout << "\t\tSection " << j + 1 << ": " << root->children[i]->children[j]->name << endl;
                for (int k = 0; k < root->children[i]->children[j]->count; k++)
                {
                    cout << "\t\t\tSubsection " << k + 1 << ": " << root->children[i]->children[j]->children[k]->name << endl;
                }
            }
        }
    }
};
int main()
{
    BookTree bt;
    bt.create();
    bt.display();
    return 0;
}