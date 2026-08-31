class Solution {
private:
    int check(int i, int j, vector<vector<int>> grid) {
        int res = 4;
        int n = grid.size();
        int m = grid[i].size();
        if (i - 1 >= 0 and grid[i - 1][j] == 1)
            res -= 1;
        if (i + 1 < n and grid[i + 1][j] == 1)
            res -= 1;
        if (j - 1 >= 0 and grid[i][j - 1] == 1)
            res -= 1;
        if (j + 1 < m and grid[i][j + 1] == 1)
            res -= 1;
        cout << i << " " << j << " " << res << endl;
        return res;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1)
                    res += check(i, j, grid);
            }
        }
        return res;
    }
};