// Last updated: 1/10/2026, 1:44:30 AM
1class Solution {
2public:
3    vector<int> nextGreaterElements(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> ans(n);
6        stack<int> st;
7
8        for(int i = 2*n - 1; i >= 0; i--) {
9            int idx = i % n;
10
11            while(!st.empty() && st.top() <= nums[idx]) {
12                st.pop();
13            }
14
15            if(st.empty()) {
16                ans[idx] = -1; 
17            } else {
18                ans[idx] = st.top();
19            }
20
21            st.push(nums[idx]);
22        }
23
24        return ans;
25    }
26};