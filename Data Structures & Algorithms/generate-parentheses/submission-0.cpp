class Solution {
private:
    vector<string> res;
    void dfs(string subset, int n, map<char, int>& m) {
        if (subset.size() == n * 2) {
            if (m['('] == m[')'])
                res.push_back(subset);
            return;
        }
        m['(']++;
        dfs(subset + "(", n, m);
        m['(']--;
        if (m['('] > m[')']) {
            m[')']++;
            dfs(subset + ")", n, m);
            m[')']--;
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string subset;
        map<char, int> m;
        m['('] = 0;
        m[')'] = 0;
        dfs(subset, n, m);
        return res;
    }
};
