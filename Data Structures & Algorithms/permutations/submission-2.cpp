class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<int> nums, vector<int>& subset, unordered_map<int, bool>& m) {
        if (subset.size() == nums.size()) {
            res.push_back(subset);
            return;
        }
        for (auto& [x, y] : m) {
            if (y == false) {
                subset.push_back(x);
                y = true;
                dfs(nums, subset, m);
                subset.pop_back();
                y = false;
            }

        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> subset;
        unordered_map<int, bool> m;
        for (auto num : nums)
            m[num] = false;
        dfs(nums, subset, m);
        return res;
    }
};
