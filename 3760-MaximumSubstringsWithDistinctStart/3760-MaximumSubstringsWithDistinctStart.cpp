// Last updated: 11/30/2025, 11:04:08 AM
1class Solution {
2public:
3    int maxDistinct(string s) {
4        int n = s.size();
5        unordered_set<char> cont;
6
7        for(int i = 0; i < n; i++) {
8            cont.insert(s[i]);
9        }
10
11        return cont.size();
12    }
13};