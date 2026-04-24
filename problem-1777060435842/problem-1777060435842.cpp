// Last updated: 4/25/2026, 1:23:55 AM
1class Solution {
2public:
3    int rec(vector<int>& nums, int i, unordered_map<int, int> &mp) {
4        if(mp.count(i)) return mp[i];
5        if(i < 0) return 0;
6
7
8        mp[i] =  max(nums[i] + rec(nums, i-2, mp), rec(nums, i-1, mp));
9        return mp[i];
10    }
11    int rob(vector<int>& nums) {
12        unordered_map<int, int> mp;
13        int ans = rec(nums, nums.size()-1, mp);
14
15        return ans;
16    }
17};