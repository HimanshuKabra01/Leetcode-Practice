// Last updated: 8/25/2026, 4:39:55 PM
1class Solution {
2public:
3    int rec(int t, int i, vector<int> &nums) {
4        if(t == 0 && i < 0) {
5            return 1;
6        }
7
8        if(i < 0) {
9            return 0;
10        }
11
12        int a = rec(t-nums[i], i-1, nums);
13        int b = rec(t+nums[i], i-1, nums);
14        
15        return a+b;
16    }
17    int findTargetSumWays(vector<int>& nums, int target) {
18        int n = nums.size();
19
20        return rec(target, n-1, nums);
21    }
22};