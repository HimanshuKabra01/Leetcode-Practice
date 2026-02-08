// Last updated: 2/8/2026, 10:49:35 AM
1class Solution {
2public:
3    int dominantIndices(vector<int>& nums) {
4       int n = nums.size();
5
6       int sum = nums[n-1];
7       int elem = 1;
8       int ans = 0;
9
10       for(int i = n - 2; i >= 0; i--) {
11        int avg = sum / elem;
12        if(nums[i] > avg) {
13            ans++;
14        }
15
16        sum += nums[i];
17        elem++;
18       }
19
20       return ans; 
21    }
22};