// Last updated: 11/29/2025, 4:06:36 PM
1class Solution {
2public:
3    bool isValid(string s) {
4        int n = s.size();
5        stack<char> st;
6
7        for(int i = 0; i < n; i++) {
8            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
9                st.push(s[i]);
10            } else {
11                if(st.size() == 0) {
12                    return false;
13                }
14
15                if(st.top() == '[' && s[i] == ']' ||
16                   st.top() == '(' && s[i] == ')' ||
17                   st.top() == '{' && s[i] == '}') {
18                    st.pop();
19                } else {
20                    return false;
21                }
22            }
23        }
24
25        return st.size() == 0;
26    }
27};