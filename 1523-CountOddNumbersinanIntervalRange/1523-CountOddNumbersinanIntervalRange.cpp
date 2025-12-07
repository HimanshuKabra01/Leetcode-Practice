// Last updated: 12/7/2025, 11:58:21 AM
1class Solution {
2public:
3    int countOdds(int low, int high) {
4        int count = 0;
5
6        for(int i = low; i <= high; i++) {
7            if(i % 2 != 0) {
8                count++;
9            }
10        }
11
12        return count;
13    }
14};