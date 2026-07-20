// Last updated: 7/20/2026, 10:15:52 PM
1class Solution {
2public:
3    bool canJump(vector<int>& nums) {
4        int n = nums.size();
5
6        if(n == 1) {
7            return true;
8        }
9
10        int far = 0;
11
12        for(int i = 0; i < n; i++) {
13            if(i > far) {
14                return false;
15            }
16            int curr = i + nums[i];
17
18            if(curr > far) {
19                far = curr;
20            }
21        }
22
23        if(far >= n-1) {
24            return true;
25        } else {
26            return false;
27        }
28    }
29};