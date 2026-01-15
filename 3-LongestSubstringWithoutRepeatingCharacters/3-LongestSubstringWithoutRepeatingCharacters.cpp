// Last updated: 1/15/2026, 6:07:01 PM
1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        int n = s.size();
5        int ans = 0;
6
7        for(int i = 0; i < n; i++) {
8            unordered_set<int> st;
9
10            for(int j = i; j < n; j++) {
11                char curr = s[j];
12
13                if(st.find(curr) != st.end()) {
14                    break;
15                }
16
17                st.insert(curr);
18
19                ans = max(ans, (int)st.size());
20            }
21        }
22
23        return ans;
24    }
25};