// Last updated: 5/15/2026, 2:18:28 PM
1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        int n = nums.size();
5
6        int st = 0;
7        int end = n - 1;
8
9        if(n == 1) {
10            return nums[0];
11        }
12
13        if(nums[0] < nums[end]) {
14            return nums[0];
15        }
16
17        while(st < end) {
18            int mid = st + (end-st)/2;
19
20            if(nums[mid] > nums[end]) {
21                st = mid + 1;
22            } else {
23                end = mid;
24            }
25        }
26
27        return nums[st];
28    }
29};