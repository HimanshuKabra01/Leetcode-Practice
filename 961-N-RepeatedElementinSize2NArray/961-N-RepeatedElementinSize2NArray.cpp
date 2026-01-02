// Last updated: 1/2/2026, 10:51:12 AM
1class Solution {
2public:
3    int repeatedNTimes(vector<int>& nums) {
4        unordered_set<int> s;
5
6        for(int i = 0; i < nums.size(); i++) {
7            if(s.find(nums[i]) != s.end()) {
8                return nums[i];
9            } else {
10                s.insert(nums[i]);
11            }
12        }
13
14        return -1;
15    }
16};