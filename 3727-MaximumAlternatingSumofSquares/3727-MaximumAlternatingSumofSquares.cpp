// Last updated: 10/13/2026, 11:49:21 PM
1class Solution {
2public:
3    long long maxAlternatingSum(vector<int>& nums) {
4        int n = nums.size();
5
6        sort(nums.begin(), nums.end());
7        int i = 0;
8        while(i < n && nums[i] < 0) {
9            nums[i] = abs(nums[i]);
10
11            i++;
12        }
13
14        sort(nums.begin(), nums.end());
15
16        int idx = 0;
17        int j = n-1;
18
19        long long ans = 0;
20
21        for(int i = 0; i < n; i++) {
22            if(i % 2 == 0) {
23                if(j >= 0) {
24                    ans += nums[j]*nums[j];
25                    j--;
26                } else {
27                    ans += nums[idx]*nums[idx];
28                    idx++;
29                }
30            } else {
31                if(idx < n) {
32                    ans -= nums[idx]*nums[idx];
33                    idx++;
34                } else {
35                    ans -= nums[j]*nums[j];
36                    j--;
37                }
38            }
39        }
40
41        return ans;
42    }
43};