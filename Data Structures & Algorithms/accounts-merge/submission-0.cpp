class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToName;        
        unordered_map<string, set<string>> m;
        for (auto account : accounts) {
            string name = account[0];
            
            for (int i = 1; i < account.size(); i++) {
                if (i > 1) {
                    m[account[1]].insert(account[i]);
                    m[account[i]].insert(account[1]);
                }
                emailToName[account[i]] = name;
            }
            m[account[1]];
        }

        vector<vector<string>> res;
        set<string> visited;
        for (auto [u, v] : m) {
            if (visited.count(u))
                continue;
            
            queue<string> q;
            q.push(u);
            vector<string> tmp = {emailToName[u]};

            while (!q.empty()) {
                string cur = q.front();
                q.pop();
                tmp.push_back(cur);
                visited.insert(cur);
                for (auto v : m[cur]) {
                    if (!visited.count(v))
                        q.push(v);
                }
            }
            sort(tmp.begin() + 1, tmp.end());
            res.push_back(tmp);
        }
        return res;
    }
};