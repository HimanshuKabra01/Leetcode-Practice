// Last updated: 4/2/2026, 2:10:51 AM
1class Solution {
2public:
3    int findContentChildren(vector<int>& g, vector<int>& s) {
4        int n = g.size();
5        int m = s.size();
6        int ans = 0;
7
8        sort(g.begin(), g.end());
9        sort(s.begin(), s.end());
10
11        int i = 0;
12        int j = 0;
13
14        while(j < m && i < n) {
15            if(s[j] >= g[i]) {
16                ans++;
17                i++;
18            }
19
20            j++;
21        }
22 
23        return ans;
24    }
25};