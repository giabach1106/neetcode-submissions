class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> m;
        vector<int> ind(n, 0);
        for (auto e : edges) {
            m[e[0]].push_back(e[1]);
            m[e[1]].push_back(e[0]);
            ind[e[0]]++;
            ind[e[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (ind[i] == 1)
                q.push(i);
        }

        vector<int> res;
        while (!q.empty()) {
            int size = q.size();
            res.clear();
            while (size--) {
                int cur = q.front();
                q.pop();
                res.push_back(cur);
                for (auto v : m[cur]) {
                    ind[v]--;
                    if (ind[v] == 1)
                        q.push(v);
                }
            }
        }
        return res;
    }
};