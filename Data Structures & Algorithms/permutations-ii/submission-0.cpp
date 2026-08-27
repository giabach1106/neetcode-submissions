class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<int>& subset, vector<int> nums, unordered_map<int, int>& m) {
        if (subset.size() == nums.size()) {
            res.push_back(subset);
            return;
        }
        for (auto& [x, y] : m) {
            if (y > 0) {
                y--;
                subset.push_back(x);
                dfs(subset, nums, m);
                subset.pop_back();
                y++;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<int> subset;
        for (auto num : nums)
            m[num]++;
        dfs(subset, nums, m);
        return res;
    }
};