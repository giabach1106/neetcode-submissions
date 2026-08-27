class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> m;
        vector<vector<int>> res = {{}};
        sort(nums.begin(), nums.end());
        for (auto num : nums) {
            int n = res.size();
            for (int i = 0; i < n; i++) {
                vector<int> subset = res[i];
                subset.push_back(num);
                if (!m.count(subset)) {
                    m.insert(subset);
                    res.push_back(subset);
                }
            }
        }
        return res;
    }
};
