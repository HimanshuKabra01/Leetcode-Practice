// Last updated: 11/20/2026, 1:59:02 AM
1class Solution {
2public:
3    int minimizeSum(vector<int>& nums) {
4        int n = nums.size();
5
6        if(n == 3) {
7            return 0;
8        }
9
10        sort(nums.begin(), nums.end());
11
12        int a = nums[n-1]-nums[2];
13        int b = nums[n-3]-nums[0];
14        int c = nums[n-2]-nums[1];
15
16        return min(a, min(b, c));
17    }
18};