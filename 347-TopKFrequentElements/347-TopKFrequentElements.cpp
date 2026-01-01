// Last updated: 1/1/2026, 9:18:00 PM
1class Solution {
2public:
3    vector<int> topKFrequent(vector<int>& nums, int k) {
4        int n = nums.size();
5
6        sort(nums.rbegin(), nums.rend());
7
8        map<int, int> mp;
9
10        for(int i = 0; i < n; i++) {
11            mp[nums[i]]++;
12        }
13
14        vector<pair<int, int>> elements(mp.begin(), mp.end());
15
16        sort(elements.begin(), elements.end(), [](const auto &a, const auto &b) {
17            return b.second < a.second;
18        });
19
20        vector<pair<int, int>> topK(elements.begin(), elements.begin() + k);
21        vector<int> ans;
22
23        for(auto &entry : topK) {
24            ans.push_back(entry.first);
25        }
26
27        return ans;
28    }
29};