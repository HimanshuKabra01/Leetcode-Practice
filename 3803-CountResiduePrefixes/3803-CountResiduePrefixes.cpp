// Last updated: 1/11/2026, 11:18:55 AM
1class Solution {
2public:
3    int centeredSubarrays(vector<int>& nums) {
4       int n = nums.size();
5       int ans = 0;
6
7        for(int i = 0; i < n; i++) {
8            int sum = 0;
9            unordered_set<int> st;
10            for(int j = i; j < n; j++) {
11                sum += nums[j];
12                st.insert(nums[j]);
13
14                if(st.find(sum) != st.end()) {
15                    ans++;
16                }
17            }
18        }
19
20        return ans;
21    }
22};