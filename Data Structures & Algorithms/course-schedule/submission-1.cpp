class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, int> ind, outd;
        for (auto pre : prerequisites) {
            outd[pre[1]]++;
            ind[pre[0]]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (outd[i] > 0 and ind[i] > 0)
                return false;
        }
        return true;
    }
};
