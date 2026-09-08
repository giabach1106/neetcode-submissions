class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> ind(numCourses, 0);

        for (auto p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            ind[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (ind[i] == 0)
                q.push(i);
        }
        
        vector<int> res = {};
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            res.push_back(u);
            for (auto v : adj[u]) {
                ind[v]--;
                if (ind[v] == 0)
                    q.push(v);
            }
        }
        return res;
    }
};
