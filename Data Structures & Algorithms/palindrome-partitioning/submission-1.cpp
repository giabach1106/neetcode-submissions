class Solution {
private:
    vector<vector<string>> res;
    vector<string> subset;
    bool check(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void dfs(int i, string s, vector<string>& subset) {
        if (i == s.size()) {
            res.push_back(subset);
            return;
        }
        for (int j = i; j < s.size(); j++) {
            if (check(s, i, j)) {
                subset.push_back(s.substr(i, j - i + 1));
                dfs(j + 1, s, subset);
                subset.pop_back();

            }
        }

    }
public:
    vector<vector<string>> partition(string s) {
        dfs(0, s, subset);
        return res;
    }
};
