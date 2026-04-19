// Last updated: 4/20/2026, 1:44:22 AM
1class Solution {
2public:
3    int rec(int n, unordered_map<int, int> &m) {
4        if(m.find(n) != m.end()) return m[n];
5
6        if(n == 1) return 1;
7        if(n == 0) return 1;
8
9        m[n] = rec(n-1, m) + rec(n-2, m);
10        return m[n];
11    }
12    int climbStairs(int n) {
13        unordered_map<int, int> m;
14
15        return rec(n, m);
16    }
17};