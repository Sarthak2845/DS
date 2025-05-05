#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

const int N = 5;

vector<string> names = {
    "College", "Library", "Cafeteria", "Hostel", "Auditorium"
};

vector<vector<int>> adjMatrix = {
    {0,1,1,0,0},
    {1,0,0,0,1},
    {1,0,0,1,0},
    {0,0,1,0,1},
    {0,1,0,1,0}
};

vector<vector<int>> adjList = {
    {1,2},    // College
    {0,4},    // Library
    {0,3},    // Cafeteria
    {2,4},    // Hostel
    {1,3}     // Auditorium
};

void DFS(int start) {
    vector<bool> visited(N, false);
    stack<int> s;
    s.push(start);
    cout << "DFS: ";
    while (!s.empty()) {
        int node = s.top(); s.pop();
        if (!visited[node]) {
            cout << names[node] << " ";
            visited[node] = true;
            for (int i = N - 1; i >= 0; --i) {
                if (adjMatrix[node][i] && !visited[i])
                    s.push(i);
            }
        }
    }
    cout << endl;
}

void BFS(int start) {
    vector<bool> visited(N, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    cout << "BFS: ";
    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << names[node] << " ";
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << endl;
}

int main() {
    DFS(0);  // Start from College
    BFS(0);
    return 0;
}
