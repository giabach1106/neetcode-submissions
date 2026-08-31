class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> m;
        for (int i = 0; i < order.size(); i++) 
            m[order[i]] = i;
        for (int k = 0; k < words.size(); k++) {
            if (k + 1 < words.size()) {
                string a = words[k];
                string b = words[k + 1];

                int i = 0;
                while (i < a.size() and i < b.size()) {
                    if (a[i] != b[i]) {
                        if (m[a[i]] > m[b[i]])
                            return false;
                        break;
                    }
                    i++;
                }
                if (i == b.size() and i < a.size())
                    return false;
            }

        }
        return true;
    }
};