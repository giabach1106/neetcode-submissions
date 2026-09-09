class Solution {
private:
    vector<vector<int>> adj;
    bool bfs(int u, int v, queue<int> q, vector<int> ind) {
        int cnt0 = -1, cnt1 = -1, i = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            i++;
            if (cur == u)
                cnt0 = i;
            if (cur == v)
                cnt1 = i;
            for (auto v : adj[cur]) {
                ind[v]--;
                if (ind[v] == 0)
                    q.push(v);
            }
        }
        if (cnt0 == -1 or cnt1 == -1)
            return false;
        return cnt0 < cnt1;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> ind(numCourses, 0);
        adj = vector<vector<int>> (numCourses);
        for (auto p : prerequisites) {
            adj[p[0]].push_back(p[1]);
            ind[p[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (ind[i] == 0)
                q.push(i);
        }
        vector<bool> res;
        for (auto qu : queries) {
            bool tmp = bfs(qu[0], qu[1], q, ind);
            res.push_back(tmp);
        }

        return res;

    }
};