class Solution {
private:
    vector<vector<int>> heights;
    bool check(int i, int j, vector<vector<bool>>& visited) {
        if (i < 0 or j < 0 or i >= visited.size() or j >= visited[i].size() or visited[i][j])
            return false;
        return true;
    }
    bool bfs(int i, int j, vector<vector<bool>>& visited) {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                if (check(x + 1, y, visited) and heights[x][y] >= heights[x + 1][y]) {
                    visited[x + 1][y] = true;
                    q.push({x + 1, y});
                }
                if (check(x - 1, y, visited) and heights[x][y] >= heights[x - 1][y]) {
                    visited[x - 1][y] = true;
                    q.push({x - 1, y});
                }              
                if (check(x, y + 1, visited) and heights[x][y] >= heights[x][y + 1]) {
                    visited[x][y + 1] = true;
                    q.push({x, y + 1});
                }
                if (check(x, y - 1, visited) and heights[x][y] >= heights[x][y - 1]) {
                    visited[x][y - 1] = true;
                    q.push({x, y - 1});
                }
            }
        }
        bool check1 = false;
        bool check2 = false;
        for (int i = 0; i < visited.size(); i++) {
            for (int j = 0; j < visited[0].size(); j++) {
                if (visited[i][j]) {
                    if (j == 0 or i == 0)
                        check1 = true;
                    if (j == visited[0].size() - 1 or i == visited.size() - 1)
                        check2 = true;
                }
                if (check1 and check2)
                    return true;
            }
        }
        return false;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->heights = heights;
        vector<vector<int>> res;
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[i].size(); j++) {
                vector<vector<bool>> visited(heights.size(), vector<bool>(heights[i].size(), false));
                if (bfs(i, j, visited)) {
                    vector<int> tmp = {i, j};
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};
