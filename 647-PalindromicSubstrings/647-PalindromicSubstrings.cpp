// Last updated: 5/5/2026, 9:08:51 PM
1class Solution {
2public:
3    int countSubstrings(string s) {
4        int ans = 0;
5
6        for(int i = 0; i < s.size(); i++) {
7            for(int len = 1; i + len <= s.size(); len++) {
8                string one = s.substr(i, len);
9                string rev = one;
10                reverse(rev.begin(), rev.end());
11
12                if(one == rev) {
13                    ans++;
14                }
15            }
16        }
17
18        return ans;
19    }
20};