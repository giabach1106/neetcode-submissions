class Solution {
private:
    vector<vector<char>> board;
    bool check(int i, int j, vector<vector<bool>>& oloc) {
        if (i < 0 or j < 0 or i >= oloc.size() or j >= oloc[0].size() or board[i][j] == 'X' or oloc[i][j] == false)
            return false;
        oloc[i][j] = false;
        return true;
    }
public:
    void solve(vector<vector<char>>& board) {
        this->board = board;
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> oloc(row, vector<bool> (col, false));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O')
                    oloc[i][j] = true;
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if ((i == 0 or j == 0 or i == row - 1 or j == col - 1) and oloc[i][j]) {
                    queue<pair<int, int>> q;
                    oloc[i][j] = false;
                    q.push({i, j});
                    while (!q.empty()) {
                        int size = q.size();
                        while (size--) {
                            auto [x, y] = q.front();
                            q.pop();
                            if (check(x + 1, y, oloc)) q.push({x + 1, y});
                            if (check(x - 1, y, oloc)) q.push({x - 1, y});
                            if (check(x, y + 1, oloc)) q.push({x, y + 1});
                            if (check(x, y - 1, oloc)) q.push({x, y - 1});
                        }
                    }
                }   
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O' and oloc[i][j] == true)
                    board[i][j] = 'X';
            }
        }

    }
};
