// Last updated: 10/19/2026, 9:54:25 PM
1class Solution {
2public:
3    vector<int> targetIndices(vector<int>& nums, int target) {
4        int n = nums.size();
5        vector<int> ans;
6
7        sort(nums.begin(), nums.end());
8
9        for(int i = 0; i < n; i++) {
10            if(nums[i] == target) {
11                ans.push_back(i);
12            }
13        }
14
15
16        return ans;
17    }
18};