// Last updated: 10/17/2026, 2:03:28 AM
1class Solution {
2public:
3    int sumCounts(vector<int>& nums) {
4        int n = nums.size();
5
6        int ans = 0;
7
8        for(int i = 0; i < n; i++) {
9            unordered_set<int> freq;
10            freq.insert(nums[i]);
11            for(int j = i; j < n; j++) {
12                freq.insert(nums[j]);
13                ans += freq.size()*freq.size();
14            }
15        }
16
17        return ans;
18    }
19};