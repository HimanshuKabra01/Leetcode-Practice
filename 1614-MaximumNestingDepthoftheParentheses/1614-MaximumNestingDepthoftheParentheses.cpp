// Last updated: 9/28/2026, 2:56:42 PM
1class Solution {
2public:
3    int maxDepth(string s) {
4        stack<char> st;
5
6        int ans = INT_MIN;
7
8        for(int i = 0; i < s.length(); i++) {
9            if(s[i] == '(') {
10                st.push('(');
11                ans = max((int)st.size(), ans);
12            } else if(s[i] == ')') {
13                st.pop();
14            }
15        }
16
17        if(ans == INT_MIN) {
18            return 0;
19        }
20
21        return ans;
22    }
23};