// Last updated: 9/8/2026, 2:05:12 PM
1class Solution {
2public:
3    int countCommas(int n) {
4       if(n < 1000) {
5        return 0;
6       } 
7        int ans = 0;
8
9       for(int i = 1000; i <= n; i++) {
10        ans++;
11       }
12
13       return ans;
14    }
15};