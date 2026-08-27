class Solution {
private:
    int dfs(vector<int> nums, int i,int res) {
        if (i == nums.size())
            return res;
        return dfs(nums, i + 1, res ^ nums[i]) + dfs(nums, i + 1, res);
    } 
public:
    int subsetXORSum(vector<int>& nums) {
        int res = dfs(nums, 0, 0);
        return res;
    }
};