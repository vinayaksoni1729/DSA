#include <iostream>
#include <queue>
using namespace std;

struct Pipe {
    bool up, down, left, right;
};

const int MAX = 1005;
int n, m, startX, startY, maxLen;
int grid[MAX][MAX];
bool visited[MAX][MAX];
Pipe pipes[MAX][MAX];

int dx[] = {-1, 1, 0, 0}; // Up, Down, Left, Right
int dy[] = {0, 0, -1, 1};

// Function to check valid grid position
bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

// BFS to explore pipes
int bfs() {
    if (grid[startX][startY] == 0) return 0;

    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    int explored = 1, level = 1;

    while (!q.empty() && level < maxLen) {
        int size = q.size();
        while (size--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // Check all 4 possible directions
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];

                if (isValid(nx, ny) && !visited[nx][ny] && grid[nx][ny] != 0) {
                    // Check if movement is allowed between pipes
                    if ((i == 0 && pipes[x][y].up && pipes[nx][ny].down) ||  // Up
                        (i == 1 && pipes[x][y].down && pipes[nx][ny].up) ||  // Down
                        (i == 2 && pipes[x][y].left && pipes[nx][ny].right) || // Left
                        (i == 3 && pipes[x][y].right && pipes[nx][ny].left)) { // Right
                        
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                        explored++;
                    }
                }
            }
        }
        level++;
    }
    return explored;
}

// Assign pipe connectivity based on type
void assignPipe(int x, int y, int type) {
    Pipe &p = pipes[x][y];

    if (type == 1) p = {true, true, true, true}; // ┼
    else if (type == 2) p = {true, true, false, false}; // │
    else if (type == 3) p = {false, false, true, true}; // ─
    else if (type == 4) p = {true, false, false, true}; // └
    else if (type == 5) p = {false, true, false, true}; // ┌
    else if (type == 6) p = {false, true, true, false}; // ┐
    else if (type == 7) p = {true, false, true, false}; // ┘
    else p = {false, false, false, false}; // Empty (0)
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> startX >> startY >> maxLen;

        // Read grid and initialize pipes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                assignPipe(i, j, grid[i][j]);
                visited[i][j] = false;
            }
        }

        // Perform BFS and print result
        cout << bfs() << "\n";
    }
    return 0;
}
