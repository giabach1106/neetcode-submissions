class Solution {
private:
    bool check(vector<vector<int>>& grid, int count, int i, int j) {
        if (i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or grid[i][j] == -1 or grid[i][j] == 0)
            return false;
        if (count < grid[i][j]) {
            grid[i][j] = count;
            return true;
        }
        return false;
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    int count = 1;
                    while (!q.empty()) {
                        int size = q.size();
                        for (int i = 0; i < size; i++) {
                            auto [x, y] = q.front();
                            q.pop();
                            if (check(grid, count, x + 1, y)) q.push({x + 1, y});
                            if (check(grid, count, x - 1, y)) q.push({x - 1, y});
                            if (check(grid, count, x, y - 1)) q.push({x, y - 1});
                            if (check(grid, count, x, y + 1)) q.push({x, y + 1});
                        }
                        count++; 
                    }
                }
            }
        }
    }
};
