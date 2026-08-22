// Last updated: 8/22/2026, 12:36:23 PM
1class Solution {
2public:
3    bool checkDivisibility(int n) {
4        int sum = 0;
5        int prod = 1;
6        int t = n;
7
8        while(t > 0) {
9            int dig = t % 10;
10
11            sum +=dig;
12            prod *= dig;
13
14            t /= 10;
15        }
16
17        return n % (sum+prod) == 0;
18    }
19};