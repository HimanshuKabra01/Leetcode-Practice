// Last updated: 9/26/2026, 9:34:45 PM
1class Solution {
2public:
3    bool rec(int i, int t, vector<int> &nums, vector<vector<int>> &dp) {
4        if(i >= nums.size() || t < 0) {
5            return false;
6        }
7
8        if(t == 0) {
9            dp[i][t] = 1;
10            return true;
11        }
12
13        if(dp[i][t] != -1) {
14            if(dp[i][t] == 1) {
15                return true;
16            } else {
17                return false;
18            }
19        }
20
21        bool cond = rec(i+1, t-nums[i], nums, dp) || rec(i+1, t, nums, dp);
22
23        if(cond) {
24            dp[i][t] = 1;
25        } else {
26            dp[i][t] = 0;
27        }
28
29        return cond;
30    }
31    bool canPartition(vector<int>& nums) {
32        int n = nums.size();
33
34        int sum = 0;
35
36        for(int i = 0; i < n; i++) {
37            sum += nums[i];
38        }
39
40        if(sum % 2 != 0) {
41            return false;
42        }
43
44        int t = sum/2;
45
46        vector<vector<int>> dp(n, vector<int>(t+1, -1));
47
48        return rec(0, t, nums, dp);
49    }
50};