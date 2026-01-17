// Last updated: 1/18/2026, 1:54:44 AM
1class Solution {
2public:
3    int minOperations(vector<int>& nums, vector<int>& target) {
4        int n = nums.size();
5        unordered_set<int> s;
6
7        for(int i = 0; i < n; i++) {
8            if(nums[i] != target[i]) {
9                s.insert(nums[i]);
10            }
11        }
12
13        return s.size();
14    }
15};