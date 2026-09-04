class Solution {
private:
    bool check (int i, int j, vector<vector<int>>& grid) {
        if (i < 0 or j < 0 or i >= grid.size() or j >= grid[i].size() or grid[i][j] != 1)
            return false;
        grid[i][j] = 2;
        return true;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                if (check(x + 1, y, grid)) q.push({x + 1, y});
                if (check(x - 1, y, grid)) q.push({x - 1, y});
                if (check(x, y - 1, grid)) q.push({x, y - 1});
                if (check(x, y + 1, grid)) q.push({x, y + 1});
            }
            count++;
        }
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == 1)
                    return -1;
        return count - 1;
    }
};
