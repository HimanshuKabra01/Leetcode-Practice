// Last updated: 11/29/2025, 3:40:59 PM
1class Solution {
2public:
3    string removeDuplicates(string s) {
4        int n = s.size();
5        stack<char> st;
6        string ans = "";
7
8        for(int i = 0; i < n; i++) {
9            if(!st.empty()) {
10                if(st.top() == s[i]) {
11                    st.pop();
12                } else {
13                    st.push(s[i]);
14                }
15            } else {
16                st.push(s[i]);
17            }
18        }
19
20        while(st.size() != 0) {
21            ans += st.top();
22
23            st.pop();
24        }
25
26        reverse(ans.begin(), ans.end());
27
28        return ans;
29    }
30};