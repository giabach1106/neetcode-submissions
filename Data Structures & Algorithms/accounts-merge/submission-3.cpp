class Solution {
private:
    void dfs(vector<string>& cur, set<string>& visited, map<string, set<string>> m, string u) {
        if (visited.count(u))
            return;
        
        visited.insert(u);
        cur.push_back(u);

        for (auto v : m[u]) {
            if (!visited.count(v))
                dfs(cur, visited, m, v);
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, set<string>> m;
        map<string, string> email_to_Name;
        for (auto account : accounts) {
            string name = account[0];

            for (int i = 1; i < account.size(); i++) {
                if (i > 1) {
                    m[account[1]].insert(account[i]);
                    m[account[i]].insert(account[1]);
                }
                email_to_Name[account[i]] = name;
            }
            m[account[1]];
        }

        set<string> visited;
        vector<vector<string>> res;

        for (auto [u, neighbors] : m) {
            if (visited.count(u))
                continue;

            vector<string> cur = {email_to_Name[u]};
            dfs(cur, visited, m, u);

            sort(cur.begin() + 1, cur.end());
            res.push_back(cur);
        }

        return res;
    }
};