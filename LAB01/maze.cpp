#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Directions for moving up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Check if a position is valid in the maze
bool is_valid(int x, int y, int n, int m, const vector<vector<int>>& maze, const vector<vector<bool>>& visited) {
    return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 0 && !visited[x][y];
}

// Function to find the shortest path to exit the maze
int bfs(int start_x, int start_y, int n, int m, const vector<vector<int>>& maze) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<pair<int, int>, int>> q;  // ((x, y), steps)

    q.push({{start_x, start_y}, 0});
    visited[start_x][start_y] = true;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        // Check if we have reached the boundary of the maze
        if (x == 0 || x == n-1 || y == 0 || y == m-1) {
            return steps;
        }

        // Explore the 4 possible directions
        for (int i = 0; i < 4; ++i) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (is_valid(new_x, new_y, n, m, maze, visited)) {
                visited[new_x][new_y] = true;
                q.push({{new_x, new_y}, steps + 1});
            }
        }
    }

    // No way to exit
    return -2;
}

int main() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;

    vector<vector<int>> maze(n, vector<int>(m));

    // Input the maze matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> maze[i][j];
        }
    }

    // Perform BFS to find the shortest path
    int result = bfs(r-1, c-1, n, m, maze);

    // Output the result
    cout << result +1<< endl;

    return 0;
}
