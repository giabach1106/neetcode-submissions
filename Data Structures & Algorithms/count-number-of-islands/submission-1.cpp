class Solution {
private:
    vector<vector<char>> grid;
    void bfs(int i, int j, vector<vector<bool>>& visited) {
        if (i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size() or visited[i][j] or grid[i][j] == '0')
            return;
        visited[i][j] = true;
        bfs(i - 1, j, visited);
        bfs(i + 1, j, visited);
        bfs(i, j - 1, visited);
        bfs(i, j + 1, visited);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        this->grid = grid;
        int res = 0;
        vector<vector<bool>> visited (grid.size(), vector<bool> (grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1' and !visited[i][j]) {
                    res++;
                    bfs(i, j, visited);
                }
            }
        }
        return res;
    }
};
