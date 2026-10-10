// Last updated: 10/10/2026, 1:11:04 PM
1class Solution {
2public:
3    string removeOuterParentheses(string s) {
4        stack<char> st;
5        string ans = "";
6
7        for(int i = 0; i < s.length(); i++) {
8            if(st.empty()) {
9                st.push(s[i]);
10            } else {
11                if(s[i] == ')' && st.top() == '(') {
12                    st.pop();
13                } else {
14                    st.push('(');
15                }
16
17                if(!st.empty()) {
18                    ans += s[i];
19                }
20            }
21        }
22
23        return ans;
24    }
25};