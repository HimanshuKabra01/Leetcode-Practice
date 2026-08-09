// Last updated: 8/9/2026, 12:29:53 PM
class Solution {
public:
    int maxDistinct(string s) {
        int n = s.size();
        unordered_set<char> cont;

        for(int i = 0; i < n; i++) {
            cont.insert(s[i]);
        }

        return cont.size();
    }
};