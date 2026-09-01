// Last updated: 9/2/2026, 1:30:15 AM
1class Solution {
2public:
3    int countSpecialIntegers(vector<int>& nums) {
4        int n = nums.size();
5        int ans = 0;
6
7        unordered_map<int, int> freq;
8        unordered_map<int, pair<int, int>> pos;
9
10        for(int i = 0; i < n; i++) {
11            freq[nums[i]]++;
12
13            if(!pos.count(nums[i])) {
14                pos[nums[i]] = {i, i};
15            } else {
16                pos[nums[i]].second = i;
17            }
18        }
19
20        for(auto &entry : pos) {
21            if((entry.second.second - entry.second.first + 1) == freq[entry.first]) {
22                ans++;
23            }
24        }
25
26        return ans;
27    }
28};