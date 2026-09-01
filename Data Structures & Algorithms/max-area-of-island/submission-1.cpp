class Solution {
private:
    vector<vector<int>> grid;
    int dfs(int i, int j, vector<vector<bool>>& visited) {
        if (i < 0 or i >= visited.size() or j < 0 or j >= visited[0].size() or visited[i][j] or grid[i][j] == 0)
            return 0;
        visited[i][j] = true;
        return 1 + dfs(i + 1, j, visited) + dfs(i - 1, j, visited) + dfs(i, j - 1, visited) + dfs(i, j + 1, visited);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->grid = grid;
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1 and visited[i][j] == false) {
                    res = max(res, dfs(i, j, visited));
                }
            }
        }
        return res;

    }
};
