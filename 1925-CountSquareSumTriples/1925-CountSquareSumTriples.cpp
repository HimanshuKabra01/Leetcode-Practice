// Last updated: 12/8/2025, 11:04:36 AM
1class Solution {
2public:
3    int countTriples(int n) {
4        int ans = 0;
5       for(int i = 1; i <= n; i++) {
6        int a = i;
7        for(int j = 1; j <= n; j++) {
8            int b = j;
9
10            int c = sqrt((a*a) + (b*b) + 1);
11
12            if(c <= n && (c*c) == (a*a) + (b*b)) {
13                ans++;
14            }
15        }
16       }
17
18       return ans;
19    }
20};