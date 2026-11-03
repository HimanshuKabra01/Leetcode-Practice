// Last updated: 11/3/2026, 10:01:29 AM
1class Solution {
2public:
3    int minMoves(vector<int>& nums) {
4        int n = nums.size();
5        int maxElement = nums[0];
6        int ans = 0;
7
8        if(n == 1) {
9            return 0;
10        }
11        for(int i = 0; i < n; i++) {
12            if(nums[i] > maxElement) {
13                maxElement = nums[i];
14            }
15        }
16
17        for(int i = 0; i < n; i++) {
18            if(maxElement != nums[i]) {
19                ans += maxElement - nums[i];
20            }
21        }
22
23        return ans;
24    }
25};