class Solution {
private:
    vector<int> nums;
    vector<vector<int>> res;
    int target;
    void dfs(int i, int sum, vector<int>& subset) {
        if (i == nums.size() or sum > target) {
            return;
        }
        if (sum == target) {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(i, sum + nums[i], subset);
        subset.pop_back();
        dfs(i + 1, sum, subset);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        this->nums = nums;
        this->target = target;
        vector<int> subset;
        dfs(0, 0, subset);
        return res;
    }
};
