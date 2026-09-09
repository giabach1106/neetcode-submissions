class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int res = 0;
        vector<bool> vis (n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                res++;
                queue<int> q;
                q.push(i);
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    vis[u] = true;
                    for (auto v : adj[u]) {
                        if (!vis[v])
                            q.push(v);
                    }
                }
            }
        }
        return res;
    }
};
