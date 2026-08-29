class Solution {
private:
    vector<vector<bool>> visited;
    bool res = false;
    vector<vector<char>> board;
    string word;
    void dfs(int i, int j, int k) {
        if (k == word.size() or i < 0 or i >= board.size() or j < 0 or j >= board[0].size() or visited[i][j] or board[i][j] != word[k])
            return;
        if ((k == word.size() - 1) and (board[i][j] == word[k])) {
            res = true;
            return;
        }
        visited[i][j] = true;
        dfs(i + 1, j, k + 1);
        dfs(i - 1, j, k + 1);
        dfs(i, j + 1, k + 1);
        dfs(i, j - 1, k + 1);
        visited[i][j] = false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        visited = vector<vector<bool>> (board.size(), vector<bool>(board[0].size(), false));
        this->board = board;
        this->word = word;
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    dfs(i, j, 0);
                    if (res == true)
                        break;
                }
            }
        }
        return res;
    }
};
