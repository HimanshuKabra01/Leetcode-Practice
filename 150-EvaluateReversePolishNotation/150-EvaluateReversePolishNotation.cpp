// Last updated: 1/12/2026, 1:45:35 AM
1class Solution {
2public:
3    int evalRPN(vector<string>& tokens) {
4        int n = tokens.size();
5        stack<int> st;
6
7        for(int i = 0; i < n; i++) {
8            if(tokens[i] == "+") {
9                int second = st.top();
10                st.pop();
11                int first = st.top();
12                st.pop();
13                int val = first + second;
14                st.push(val);
15            } else if(tokens[i] == "-") {
16                int second = st.top();
17                st.pop();
18                int first = st.top();
19                st.pop();
20
21                int val = first - second;
22                st.push(val);
23            } else if(tokens[i] == "*") {
24                int second = st.top();
25                st.pop();
26                int first = st.top();
27                st.pop();
28
29                int val = first * second;
30                st.push(val);
31            } else if(tokens[i] == "/") {
32                int second = st.top();
33                st.pop();
34                int first = st.top();
35                st.pop();
36
37                int val = first / second;
38                st.push(val);
39            } else {
40                st.push(stoi(tokens[i]));
41            }
42        }
43
44        return st.top();
45    }
46};