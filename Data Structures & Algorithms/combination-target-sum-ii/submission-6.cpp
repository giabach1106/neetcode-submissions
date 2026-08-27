class Solution {
private:
    vector<vector<int>> res;
    vector<int> subset;
    vector<int> candidates;
    int target;
    void dfs(int i, int sum, vector<int>& subset) {
        if (sum == target) {
            res.push_back(subset);
            return;
        }
        if (i == candidates.size() or sum > target)
            return;
        
        subset.push_back(candidates[i]);
        dfs(i + 1, sum + candidates[i], subset);
        subset.pop_back();
        while (i + 1 < candidates.size() and candidates[i] == candidates[i + 1])
            i++;
        dfs(i + 1, sum, subset);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->target = target;
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        dfs(0, 0, subset);
        return res;    
    }
};
