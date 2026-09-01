class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int, vector<int>> m;
        for (int i = 0; i < trust.size(); i++) {
            m[trust[i][1]].push_back(trust[i][0]);
        }
        int res = -1;
        for (auto [x, y] : m) {
            if (y.size() == n - 1) {
                bool check = true;
                for (int i = 0; i < trust.size(); i++) {
                    if (trust[i][0] == x) {
                        check = false;
                        break;
                    }
                }
                if (check)
                    res = x;
            }    
        }
        return res;

    }
};