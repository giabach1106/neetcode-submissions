class Solution {
private:
    int res = 0;
    int n;
    void fill(int r, int c, vector<vector<int>>& visited) {
        for (int i = 0; i < n; i++) {
            visited[r][i]++;
            visited[i][c]++;
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
            visited[r][i]--;
            visited[i][c]--;
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
    void dfs(int count, vector<vector<int>>& visited) {
        if (count == n) {
            res++;
            return;
        }
        int r = count;
        for (int c = 0; c < n; c++) {
            if (visited[r][c] > 0)
                continue;
            fill(r, c, visited);
            dfs(count + 1, visited);
            unfill(r, c, visited);
        }
    }
public:
    int totalNQueens(int n) {
        this->n = n;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        dfs(0, visited);
        return res;
    }
};