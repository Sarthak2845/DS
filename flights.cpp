#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

unordered_map<string, vector<pair<string, float>>> flightGraph;

void addFlight(const string& from, const string& to, float time) {
    flightGraph[from].push_back({to, time});
}

void printGraph() {
    for (const auto& city : flightGraph) {
        cout << city.first << " -> ";
        for (const auto& neighbor : city.second) {
            cout << "(" << neighbor.first << ", " << neighbor.second << " hrs) ";
        }
        cout << endl;
    }
}

int main() {

    addFlight("Delhi", "Mumbai", 2.0);
    addFlight("Delhi", "Bangalore", 3.0);
    addFlight("Mumbai", "Kolkata", 4.0);
    addFlight("Bangalore", "Kolkata", 1.5);

    printGraph();

    return 0;
}
