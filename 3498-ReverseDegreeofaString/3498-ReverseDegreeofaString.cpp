// Last updated: 9/20/2026, 10:57:31 AM
1class Solution {
2public:
3    int reverseDegree(string s) {
4        int ans = 0;
5
6        for(int i = 0; i < s.length(); i++) {
7            ans += (26-(s[i]-'a'))*(i+1);
8        }
9
10        return ans;
11    }
12};