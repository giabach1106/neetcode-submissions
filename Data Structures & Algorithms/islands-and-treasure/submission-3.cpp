class Solution {
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
                            if (check(x + 1, y)) q.push({x + 1, y});
                            if (check(x + 1, y)) q.push({x + 1, y});
                        }
                        count++; 
                    }
                }
            }
        }
    }
};
