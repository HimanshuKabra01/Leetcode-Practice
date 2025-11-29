// Last updated: 11/29/2025, 11:28:07 AM
1class Solution {
2public:
3    int minOperations(vector<int>& nums, int k) {
4        int n = nums.size();
5        int sum = 0;
6
7        for(int i = 0; i < n; i++) {
8            sum += nums[i];
9        }
10
11        return sum % k;
12    }
13};