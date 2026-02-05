// Last updated: 2/5/2026, 10:20:01 PM
1class Solution {
2public:
3    vector<int> constructTransformedArray(vector<int>& nums) {
4        int n = nums.size();
5
6        vector<int> ans(n);
7
8        for(int i = 0; i < n; i++) {
9            if(nums[i] > 0) {
10                int idx = i + nums[i];
11
12                ans[i] = nums[(idx % n)];
13            } else if(nums[i] < 0) {
14                int idx = i - abs(nums[i]);
15
16                ans[i] = nums[( (idx % n) + n ) % n];
17            } else {
18                ans[i] = nums[i];
19            }
20        }
21
22        return ans;
23    }
24};