// Last updated: 1/3/2026, 9:33:42 PM
1class Solution {
2public:
3    string reversePrefix(string s, int k) {
4        reverse(s.begin(), s.begin() + k);
5
6        return s;
7    }
8};