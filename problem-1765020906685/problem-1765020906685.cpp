// Last updated: 12/6/2025, 5:05:06 PM
1class Solution {
2public:
3    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
4        int n = nums1.size();
5        int m = nums2.size();
6        vector<int> ans(n);
7        vector<int> next(m);
8        stack<int> st;
9
10        for(int i = m - 1; i >= 0; i--) {
11            while(!st.empty() && nums2[i] > st.top()) {
12                st.pop();
13            }
14
15            if(st.empty()) {
16                next[i] = -1;
17            } else {
18                next[i] = st.top();
19            }
20
21            st.push(nums2[i]);
22        }
23
24        for(int i = 0; i < n; i++) {
25            for(int j = 0; j < m; j++) {
26                if(nums1[i] == nums2[j]) {
27                    ans[i] = next[j];
28                }
29            }
30        }
31
32        return ans;
33    }
34};