class Solution {
private:
    bool dfs(double cur, set<string>& visited, map<string, vector<pair<string, double>>> m, string u, string target, double& ans) {
        if (u == target) {
            ans = cur;
            return true;
        }
        visited.insert(u);
        for (auto [v, value] : m[u]) {
            if (!visited.count(v)) {
                if (dfs(cur * value, visited, m, v, target, ans))
                    return true;
            }
        }
        return false;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> m;
        int i = 0;
        for (auto equation : equations) {
            string a = equation[0];
            string b = equation[1];
            m[a].push_back({b, values[i]});
            m[b].push_back({a, 1 / values[i]});
            i++; 
        }
        
        vector<double> res;
        for (auto q : queries) {
            string a = q[0];
            string b = q[1];
            if (a == b) {
                if (!m.count(a)) {
                    res.push_back((double) -1.00);
                    continue;
                }
                res.push_back((double)1.00);
                continue;
            }
            
            double ans = -1.0;
            set<string> visited;
            dfs(1.0, visited, m, a, b, ans);
            res.push_back(ans);
        }
        
        return res;
    }
};