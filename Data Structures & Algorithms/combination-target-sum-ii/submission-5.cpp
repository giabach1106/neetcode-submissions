class Solution {
private:
    vector<vector<int>> res;
    vector<int> subset;
    vector<int> candidates;
    int target;
    set<vector<int>> m;
    void dfs(int i, int sum, vector<int>& subset, set<vector<int>>& m) {
        if (sum == target) {
            if (m.count(subset))
                return;
            m.insert(subset);
            res.push_back(subset);
            return;
        }
        if (i == candidates.size() or sum > target)
            return;
        subset.push_back(candidates[i]);
        dfs(i + 1, sum + candidates[i], subset, m);
        subset.pop_back();
        dfs(i + 1, sum, subset, m);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->target = target;
        this->candidates = candidates;
        dfs(0, 0, subset, m);
        return res;    
    }
};
