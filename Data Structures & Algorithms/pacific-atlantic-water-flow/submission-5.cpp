class Solution {
private:
    vector<vector<int>> heights;
    bool check(int i, int j, vector<vector<bool>>& tmp) {
        if (i < 0 or j < 0 or i >= tmp.size() or j >= tmp[0].size() or tmp[i][j])
            return false;
        return true;
    }
    void bfs(int i, int j, vector<vector<bool>>& tmp) {
        if (tmp[i][j])
            return;
        tmp[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                if (check(x + 1, y, tmp) and heights[x][y] <= heights[x + 1][y]) {
                    tmp[x + 1][y] = true;
                    q.push({x + 1, y});
                }
                if (check(x - 1, y, tmp) and heights[x][y] <= heights[x - 1][y]) {
                    tmp[x - 1][y] = true;
                    q.push({x - 1, y});
                }
                if (check(x, y + 1, tmp) and heights[x][y] <= heights[x][y + 1]) {
                    tmp[x][y + 1] = true;
                    q.push({x, y + 1});
                }
                if (check(x, y - 1, tmp) and heights[x][y] <= heights[x][y - 1]) {
                    tmp[x][y - 1] = true;
                    q.push({x, y - 1});
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->heights = heights;
        vector<vector<int>> res;
        vector<vector<bool>> pac (heights.size(), vector<bool> (heights[0].size(), false));
        vector<vector<bool>> atl (heights.size(), vector<bool> (heights[0].size(), false));
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[i].size(); j++) {
                if (i == 0 or j == 0) {
                    bfs(i, j, pac);
                }
                if (i == heights.size() - 1 or j == heights[0].size() - 1)
                    bfs(i, j, atl);
            }
        }
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[i].size(); j++) {
                if (pac[i][j] and atl[i][j]) {
                    vector<int> tmp = {i, j};
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};
