class Solution {
private:
    void bfs(int count, int i = 0, int j = 0, vector<vector<bool>>& visited, vector<vector<int>>& grid) {
        if (i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size() or grid[i][j] != 2147483647 or visited[i][j])
            return;
        visited[i][j] = true;
        grid[i][j] = count;
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int [x, y] = q.front();
                q.pop();
                q.push({x, y});
                q.push({x, y});
                q.push({x, y});
            }
        }
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        this->grid = grid;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    vector<vector<bool>> visited (grid.size(), vector<bool> (grid[0].size(), false));
                    bfs(1, i, j, visited, grid);
                }
            }
        }
        return;
    }
};
