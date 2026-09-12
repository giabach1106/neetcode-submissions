class Solution {
private:
    map<string, vector<pair<string, double>>> m;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int i = 0;
        for (auto e : equations) {
            m[e[0]].push_back({e[1], values[i]});
            m[e[1]].push_back({e[0], 1 / values[i]});
            i++;
        }

        vector<double> res;
        for (auto query : queries) {
            string start = query[0], target = query[1];
            if (!m.count(start) or !m.count(target)) {
                res.push_back((double) -1);
                continue;
            }
            
            queue<pair<string, double>> q;
            q.push({start, 1.0});
            set<string> visited;
            visited.insert(start);

            double ans = -1.0;
            while (!q.empty()) {
                auto [u, product] = q.front();
                q.pop();
                if (u == target) {
                    ans = product;
                    break;
                }
                for (auto [v, value] : m[u]) {
                    if (!visited.count(v)) {
                        q.push({v, product * value});
                    }
                }
            }

            res.push_back(ans);
        }
        return res;
    }
};