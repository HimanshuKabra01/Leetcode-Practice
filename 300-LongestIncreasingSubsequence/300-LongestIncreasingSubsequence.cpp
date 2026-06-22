// Last updated: 6/23/2026, 12:46:14 AM
1class Solution {
2public:
3    int rec(vector<int> &memo, vector<int> &nums, int i) {
4        if(i == 0) {
5            memo[i] = 1;
6            return memo[i];
7        }
8
9        if(memo[i] != INT_MAX) {
10            return memo[i];
11        }
12
13        memo[i] = 1;
14        for(int j = 0; j < i; j++) {
15            if(nums[i] > nums[j]) {
16                int val = rec(memo, nums, j);
17
18                memo[i] = max(memo[i], val+1);
19            }
20        }
21
22        return memo[i];
23    }
24    int lengthOfLIS(vector<int>& nums) {
25        int n = nums.size();
26        vector<int> memo(n, INT_MAX);
27
28        int ans = INT_MIN;
29
30        for(int i = 0; i < n; i++) {
31            ans = max(ans, rec(memo, nums, i));
32        }
33
34        return ans;
35    }
36};