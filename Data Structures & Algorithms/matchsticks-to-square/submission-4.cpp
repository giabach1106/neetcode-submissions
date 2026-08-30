class Solution {
private:
    int sum = 0;
    bool res = false;
    void dfs(int i, int cur, map<int, int>& m) {
        if (cur > sum)
            return;
        if (i == 3) {
            res = true;
            return;
        }
        if (cur == sum) {
            dfs(i + 1, 0, m);
            return;
        }
        for (auto& [x, y] : m) {
            if (y == 0)
                continue;
            if (x + cur > sum)
                continue;
            else {
                y--;
                dfs(i, cur + x, m);
                y++;
            }
        }

    }
public:
    bool makesquare(vector<int>& matchsticks) {
        map<int, int> m;
        for (auto matchstick : matchsticks) {
            sum += matchstick;
            m[matchstick]++;
        }
        if (sum % 4 != 0)
            return false;
        sum /= 4;
        dfs(0, 0, m);
        return res;
    }
};