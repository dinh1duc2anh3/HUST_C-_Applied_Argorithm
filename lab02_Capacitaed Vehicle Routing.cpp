#include <iostream>
#include <vector>
#include <limits>
#include <algorithm> // For std::all_of

using namespace std;

int n, K, Q; // Number of clients, Number of trucks, Capacity of trucks
vector<int> demand; // Demand for each client
vector<vector<int>> distMatrix; // Distance matrix (renamed)
vector<bool> visited; // To track visited clients
int minDistance = numeric_limits<int>::max(); // Minimum distance found

void backtrack(int truckIndex, int currentDistance, int currentLoad, vector<int> route) {
    // If we have assigned all trucks
    if (truckIndex == K) {
        // If all clients are visited and the current distance is valid
        if (all_of(visited.begin() + 1, visited.end(), [](bool v) { return v; })) {
            minDistance = min(minDistance, currentDistance);
        }
        return;
    }

    // Case where the truck does not visit any clients (empty route)
    // Add distance to return to the depot
    backtrack(truckIndex + 1, currentDistance + distMatrix[0][0], 0, {});

    // Try all clients
    for (int i = 1; i <= n; ++i) {
        if (!visited[i] && currentLoad + demand[i - 1] <= Q) { // If client is not visited and truck can carry more
            visited[i] = true;

            // Calculate new distance from the last visited client (if any) to the new client
            int newDistance = (route.empty()) ? distMatrix[0][i] : distMatrix[route.back()][i];
            route.push_back(i);

            // Recursive call with updated parameters
            backtrack(truckIndex, currentDistance + newDistance, currentLoad + demand[i - 1], route);

            route.pop_back(); // Backtrack
            visited[i] = false; // Mark as unvisited
        }
    }
}

int main() {
    // Input
    cin >> n >> K >> Q;
    demand.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> demand[i];
    }
    distMatrix.resize(n + 1, vector<int>(n + 1, 0)); // Use the new name
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cin >> distMatrix[i][j]; // Use the new name
        }
    }

    // Initialize visited array
    visited.resize(n + 1, false);

    // Start backtracking
    backtrack(0, 0, 0, {});

    // Output the minimum distance
    cout << minDistance << endl;

    return 0;
}
