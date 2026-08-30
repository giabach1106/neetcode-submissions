class Solution {
private:
    vector<string> res;
    vector<string> ch = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void dfs(int i, string digits, string substr) {
        if (i == digits.size()) {
            res.push_back(substr);
            return;
        }
        string curStr = ch[digits[i] - '0'];
        for (auto c : curStr) {
            dfs(i + 1, digits, substr + c);
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        string substr;
        if(digits == "")
            return {};
        dfs(0, digits, substr);
        return res;
    }
};
