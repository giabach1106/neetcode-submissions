class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        int count = 0;
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = true;
            count++; 
            for (auto v : adj[u]) {
                if (!vis[v]) {
                    q.push(v);
                }
            }
        }
        return n == count;
    }
};
