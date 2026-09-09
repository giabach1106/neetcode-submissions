class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size() + 1);
        vector<int> ind (edges.size() + 1, 0);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            ind[e[0]]++;
            ind[e[1]]++;
        }    
        queue<int> q;    
        for (int i = 1; i <= edges.size(); i++) {
            if (ind[i] == 1)
                q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : adj[u]) {
                ind[v]--;
                if (ind[v] == 1)
                    q.push(v);
            }
        }

        for (int i = edges.size() - 1; i >= 0; i--) {
            auto p = edges[i];
            int x = p[0], y = p[1];
            if (ind[x] == 2 and ind[y] == 2)
                return {x, y};
        }
        return {};
    }
};
