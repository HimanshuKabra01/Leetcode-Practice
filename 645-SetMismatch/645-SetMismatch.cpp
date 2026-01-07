// Last updated: 1/7/2026, 12:17:10 PM
1class Solution {
2public:
3    vector<int> findErrorNums(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> ans;
6        unordered_set<int> s;
7
8        sort(nums.begin(), nums.end());
9
10        for(int i = 0; i < n; i++) {
11            if(s.find(nums[i]) != s.end()) {
12                ans.push_back(nums[i]);
13            } else {
14                s.insert(nums[i]);
15            }
16        }
17
18        for(int i = 1; i <= n; i++) {
19            if(s.find(i) == s.end()) {
20                ans.push_back(i);
21                break;
22            }
23        }
24
25        return ans;
26    }
27};