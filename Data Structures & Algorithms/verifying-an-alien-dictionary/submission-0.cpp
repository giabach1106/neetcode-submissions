class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> m;
        for (int i = 0; i < order.size(); i++) 
            m[order[i]] = i;
        for (int i = 0; i < words.size(); i++) {
            if (i + 1 < words.size()) {
            string a = words[i];

            }

        }
        return true;
    }
};