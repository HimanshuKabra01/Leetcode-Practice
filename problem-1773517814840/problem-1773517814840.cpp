// Last updated: 3/15/2026, 1:20:14 AM
1class Solution {
2public:
3    int firstUniqueEven(vector<int>& nums) {
4        int n = nums.size();
5        unordered_map<int, int> mp;
6
7        for(int i = 0; i < n; i++) {
8            mp[nums[i]]++;
9        }
10
11        int ans = -1;
12        for(int i = 0; i < n; i++) {
13            if(nums[i] % 2 == 0) {
14                if(mp[nums[i]] == 1) {
15                    ans = nums[i];
16                    break;
17                }
18            } else {
19                continue;
20            }
21        }
22
23        return ans;
24    }
25};