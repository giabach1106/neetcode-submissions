class Solution {
private:
    int sum = 0;
    bool res = false;
    vector<int> nums;
    int k;

    void dfs(int i, int cur) {
        if (cur > sum)
            return;
        if (i == k - 1) {
            res = true;
            return;
        }
        if (cur == sum) {
            dfs(i + 1, 0);
            return;
        }    
        for (auto num : nums) {
            if (cur + num > sum)
                continue;
            else {
                dfs(i, cur + num);
                if (res)
                    return;
            }
        }
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        this->nums = nums;
        this->k = k;
        for (auto num : nums)
            sum += num;
        if (sum % k != 0)
            return false;
        sum /= k;
        dfs(0, 0);
        return res;
    }
};