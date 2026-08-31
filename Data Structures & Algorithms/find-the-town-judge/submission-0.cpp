class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int, vector<int>> m;
        for (int i = 0; i < trust.size(); i++) {
            m[trust[i][1]].push_back(trust[i][0]);
        }
        int res = -1;
        if (m.size() == 1)
            for (auto [x, y] : m)
                return x;
        return res;   

    }
};