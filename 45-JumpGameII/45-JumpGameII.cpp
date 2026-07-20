// Last updated: 7/21/2026, 1:39:31 AM
1class Solution {
2public:
3    int jump(vector<int>& nums) {
4        int n = nums.size();
5
6        int ans = 0;
7        int currEnd = 0;
8
9        if(n==1) {
10            return 0;
11        }
12
13        int far = 0;
14
15        for(int i = 0; i < n; i++) {
16            int curr = i + nums[i];
17
18            far = max(curr, far);
19
20            if(i == currEnd && i != n-1) {
21                ans++;
22                currEnd = far;
23            }
24        }
25
26        return ans;
27    }
28};