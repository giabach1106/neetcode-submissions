class Solution {
private:
    bool res = false;
    vector<vector<char>> board;
    string word;
    void dfs(int i, int j, int k) {
        if (k == word.size()) {
            res = true;
            return;
        }
        if (i < 0 or i >= board.size() or j < 0 or j >= board[i].size())
            return;
        if (board[i][j] != word[k])
            return;
        dfs(i + 1, j, k + 1);
        dfs(i - 1, j, k + 1);
        dfs(i, j + 1, k + 1);
        dfs(i, j - 1, k + 1);
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                dfs(i, j, 0);
                if (res == true)
                    return true;
            }
        }
        return res;
    }
};
