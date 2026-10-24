// Last updated: 10/24/2026, 6:12:20 PM
1class Solution {
2public:
3    int rec(int i, int j, string &s, vector<vector<int>> &dp) {
4        int n = s.length();
5
6        if(i >= n || j < 0 ) {
7            return 0;
8        }
9
10        if(i == j || i > j) {
11            return 1;
12        }
13
14        if(dp[i][j] != -1) {
15            return dp[i][j];
16        }
17
18        if(s[i] == s[j]) {
19            return dp[i][j] = rec(i+1, j-1, s, dp);
20        } else {
21            return dp[i][j] = 0;
22        }
23    }
24    string longestPalindrome(string s) {
25        int n = s.length();
26
27        vector<vector<int>> dp(n, vector<int>(n, -1));
28        int st = -1;
29        int mx = 0;
30        
31        for(int i = 0; i < n; i++) {
32            for(int j = 0; j < n; j++) {
33                if(rec(i, j, s, dp) == 1) {
34                    if(j-i+1 > mx) {
35                        mx = j-i+1;
36                        st = i;
37                    }
38                }
39            }
40        }
41
42        return s.substr(st, mx);
43    }
44};