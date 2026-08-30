class Solution {
private:
    vector<vector<string>> res;
    int n;
    void fill(int r, int c, vector<vector<int>>& visited) {
        for (int i = 0; i < n; i++) {
            visited[i][c]++;
            visited[r][i]++;
        }
        for (int i = r, j = c; i >= 0 and j >= 0; i--, j--) {
            visited[i][j]++;
        }
        for (int i = r + 1, j = c + 1; i < n and j < n; i++, j++) {
            visited[i][j]++;
        }

        for (int i = r, j = c; i >= 0 and j < n; i--, j++) {
            visited[i][j]++;
        }
        for (int i = r + 1, j = c - 1; i < n and j >= 0; i++, j--) {
            visited[i][j]++;
        }
    }

    void unfill(int r, int c, vector<vector<int>>& visited) {
        for (int i = 0; i < n; i++) {
            visited[i][c]--;
            visited[r][i]--;
        }
        for (int i = r, j = c; i >= 0 and j >= 0; i--, j--) {
            visited[i][j]--;
        }
        for (int i = r + 1, j = c + 1; i < n and j < n; i++, j++) {
            visited[i][j]--;
        }

        for (int i = r, j = c; i >= 0 and j < n; i--, j++) {
            visited[i][j]--;
        }
        for (int i = r + 1, j = c - 1; i < n and j >= 0; i++, j--) {
            visited[i][j]--;
        }
    }
    void dfs(int count, vector<string>& substring, vector<vector<int>>& visited) {
        if (count == n) {
            res.push_back(substring);
            return;
        }
        int r = count;
        for (int c = 0; c < n; c++) {
            if (visited[r][c] > 0) 
                continue;
            string cur (n, '.');
            cur[c] = 'Q';
            substring.push_back(cur);

            fill(r, c, visited);
            dfs(count + 1, substring, visited);

            unfill(r, c, visited);
            substring.pop_back();
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        vector<vector<int>> visited (n, vector<int>(n, 0));
        vector<string> substring;
        dfs(0, substring, visited);
        return res;
    }
};
