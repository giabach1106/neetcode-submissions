class Solution {
private:
    string s; 
    set<string> hashset; 
    vector<string> res;
    void dfs(int cur, string substring) {
        if (cur == s.size()) {
            substring.pop_back();
            res.push_back(substring);
            return;
        }
        for (int i = cur; i < s.size(); i++) {
            string tmp = s.substr(cur, i - cur + 1);
            if (hashset.count(tmp)) {
                dfs(i + 1, substring + tmp + " ");

            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string substring;
        this->s = s;
        for (auto word : wordDict) 
            hashset.insert(word);  
        dfs(0, "");
        return res;
    }
};