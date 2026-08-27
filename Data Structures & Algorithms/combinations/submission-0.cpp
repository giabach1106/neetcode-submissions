class Solution {
private:
    int k;
    int n;
    vector<vector<int>> res;
    void dfs(int i, vector<int> nums, vector<int>& subset) {
        if (subset.size() == k) {
            res.push_back(subset);
            return;
        }
        if (i == n)
            return;
        subset.push_back(nums[i]);
        dfs(i + 1, nums, subset);
        subset.pop_back();
        dfs(i + 1, nums, subset);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        vector<int> nums;
        for (int i = 1; i <= n; i++)
            nums.push_back(i);
        vector<int> subset;
        dfs(0, nums, subset);
        return res;
    }
};