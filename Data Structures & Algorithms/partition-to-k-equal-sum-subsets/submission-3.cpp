class Solution {
private:
    int sum = 0;
    bool res = false;
    vector<int> nums;
    int k;

    void dfs(int i, int cur, vector<bool>& visited) {
        if (cur > sum)
            return;
        if (i == k - 1) {
            res = true;
            return;
        }
        if (cur == sum) {
            dfs(i + 1, 0, visited);
            return;
        }    
        for (int j = 0; j < nums.size(); j++) {
            if (visited[j] or nums[j] + cur > sum)
                continue;
            else {
                visited[j] = true;
                dfs(i, cur + nums[j], visited);
                visited[j] = false;
            }
        }
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        this->nums = nums;
        this->k = k;
        sort(nums.begin(), nums.end());
        for (auto num : nums)
            sum += num;
        if (sum % k != 0)
            return false;
        sum /= k;
        vector<bool> visited (nums.size(), false);
        dfs(0, 0, visited);
        return res;
    }
};