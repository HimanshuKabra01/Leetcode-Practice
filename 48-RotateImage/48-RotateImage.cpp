// Last updated: 12/17/2025, 11:55:39 PM
1class Solution {
2public:
3    int reverseBits(int n) {
4        long long result = 0;
5
6        for(int i = 0; i < 32; i++) {
7            result <<= 1;
8
9            if(n & 1) {
10                result++;
11            }
12
13            n >>= 1;
14        }
15
16        return result;
17    }
18};