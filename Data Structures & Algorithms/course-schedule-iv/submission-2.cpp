class Solution {
private:
    vector<vector<int>> adj;
    int numCourses;
    bool bfs(int u, int v) {
        queue<int> q;
        q.push(u);
        vector<bool> visited(numCourses, false);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            visited[cur] = true;

            for (auto i : adj[cur]) {
                if (i == v)
                    return true;
                if (!visited[i])
                    q.push(i);
            }
        }
        return false;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        this->numCourses = numCourses;
        adj = vector<vector<int>> (numCourses);
        for (auto p : prerequisites) {
            adj[p[0]].push_back(p[1]);
        }

        vector<bool> res;
        for (auto q : queries) {
            bool tmp = bfs(q[0], q[1]);
            res.push_back(tmp);
        }

        return res;
    }
};