// Last updated: 7/16/2026, 12:28:18 AM
1class Solution {
2public:
3    int longestConsecutive(vector<int>& nums) {
4        int n = nums.size();
5        if(n == 0) {
6            return 0;
7        }
8
9        unordered_set<int> st;
10
11        for(int i = 0; i < n; i++) {
12            st.insert(nums[i]);
13        }
14
15        int ans = 0;
16        int curr = 0;
17        int num = 0;
18        for(int x : st) {
19            if(st.find(x-1) == st.end()) {
20                num = x;
21                num++;
22                curr++;
23
24                while(st.find(num) != st.end()) {
25                    curr++;
26                    num++;
27                }
28
29                ans = max(curr, ans);
30                curr = 0;
31            } else {
32                curr = 0;
33            }
34        }
35
36        return ans;
37    }
38};