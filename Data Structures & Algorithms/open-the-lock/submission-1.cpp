class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        q.push("0000");
        int count = 0;
        set<string> s(deadends.begin(), deadends.end());
        if (s.count("0000"));
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string cur = q.front();
                q.pop();
                if (cur == target)
                    return count;
                
                for (int i = 0; i < 4; i++) {
                    for (int dir : {-1, 1}) {
                        string tmp = cur;
                        tmp[i] = (tmp[i] - '0' + dir + 10) % 10 + '0';
                        if (s.count(tmp))
                            continue;
                        q.push(tmp);
                        s.insert(tmp);
                    }
                }
            }
            count++;
        }
        return -1;
    }
};