// Last updated: 12/5/2025, 10:05:21 PM
1class Solution {
2public:
3    int countPartitions(vector<int>& nums) {
4        int totalSum = 0;
5
6        for(int x : nums) {
7            totalSum += x;
8        }
9
10        if(totalSum % 2 != 0) {
11            return 0;
12        } else {
13            return nums.size() - 1;
14        }
15    }
16};