// Last updated: 9/21/2025, 8:04:55 PM
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if(s == t) {
            return true;
        }

        return false;
    }
};