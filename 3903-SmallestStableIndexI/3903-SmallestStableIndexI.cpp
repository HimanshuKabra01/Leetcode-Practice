// Last updated: 9/4/2026, 5:29:46 PM
1class Solution {
2public:
3    int firstStableIndex(vector<int>& nums, int k) {
4        int n = nums.size();
5
6        vector<pair<int, int>> elem(n);
7        int mx = nums[0];
8        elem[0].first = mx;
9        int mn = nums[n-1];
10        elem[n-1].second = mn;
11
12        for(int i = 1; i < n; i++) {
13            if(nums[i] > mx) {
14                mx = nums[i];
15            }
16
17            elem[i].first = mx;
18        } 
19
20        for(int i = n-2; i >= 0; i--) {
21            if(nums[i] < mn) {
22                mn = nums[i];
23            }
24
25            elem[i].second = mn;
26        } 
27
28        for(int i = 0; i < n; i++) {
29            int score = elem[i].first - elem[i].second;
30
31            if(score <= k) {
32                return i;
33            }
34        }
35
36        return -1;
37    }
38};