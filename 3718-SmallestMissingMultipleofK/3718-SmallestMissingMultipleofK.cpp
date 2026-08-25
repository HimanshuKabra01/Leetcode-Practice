// Last updated: 8/26/2026, 1:18:43 AM
1class Solution {
2public:
3    int missingMultiple(vector<int>& nums, int k) {
4        unordered_set<int> st;
5        int n = nums.size();
6
7        for(int i = 0; i < n; i++) {
8            st.insert(nums[i]);
9        }
10
11        int i = 1;
12
13        while(true) {
14            int prod = k*i;
15
16            if(st.find(prod) == st.end()) {
17                return prod;
18            }
19
20            i++;
21        }
22
23        return 0;
24    }
25};