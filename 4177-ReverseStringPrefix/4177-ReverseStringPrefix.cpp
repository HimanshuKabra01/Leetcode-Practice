// Last updated: 8/9/2026, 12:29:31 PM
class Solution {
public:
    string reversePrefix(string s, int k) {
        reverse(s.begin(), s.begin() + k);

        return s;
    }
};