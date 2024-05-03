#include <iostream>
#include <vector>
#include <queue>

int bfs(std::vector<std::vector<int>>& grid) {
    std::queue<std::pair<int, int>> q;
    int time = 0;
    int freshCount = 0;

    // Initial population of the queue with all rotten oranges and count fresh oranges
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            } else if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }

    // Directions for the 4-adjacent cells
    std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // BFS
    while (!q.empty() && freshCount > 0) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2; // Become rotten
                    q.push({nx, ny});
                    freshCount--;
                }
            }
        }
        time++;
    }

    return freshCount == 0 ? time : -1;
}

int main() {
    std::vector<std::vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    std::cout << bfs(grid) << std::endl;
    return 0;
}
