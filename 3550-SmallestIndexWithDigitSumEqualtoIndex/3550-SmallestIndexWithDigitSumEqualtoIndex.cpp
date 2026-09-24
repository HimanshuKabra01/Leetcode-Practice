// Last updated: 9/24/2026, 4:50:49 PM
1class Solution {
2public:
3    int smallestIndex(vector<int>& nums) {
4        int n = nums.size();
5
6        for(int i = 0; i < n; i++) {
7            int sum = 0;
8            while(nums[i] != 0) {
9                int dig = nums[i] % 10;
10
11                sum += dig;
12
13                nums[i] /= 10;
14            }
15
16            if(sum == i) {
17                return i;
18            }
19        }
20
21        return -1;
22    }
23};