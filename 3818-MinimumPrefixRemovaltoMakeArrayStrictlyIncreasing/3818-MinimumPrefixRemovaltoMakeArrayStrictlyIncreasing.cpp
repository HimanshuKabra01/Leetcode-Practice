// Last updated: 1/25/2026, 11:18:14 AM
1class Solution {
2public:
3    int minimumPrefixLength(vector<int>& nums) {
4        int n = nums.size();
5
6        int ans = 0;
7
8        for(int i = n - 1; i > 0; i--) {
9            if(nums[i] - nums[i-1] > 0) {
10                ans++;
11            } else {
12                break;
13            }
14        }
15
16        return n - ans -1;
17    }
18};