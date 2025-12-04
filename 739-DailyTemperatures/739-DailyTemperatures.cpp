// Last updated: 12/4/2025, 4:28:27 PM
1class Solution {
2public:
3    vector<int> dailyTemperatures(vector<int>& temperatures) {
4        int n = temperatures.size();
5        vector<int> ans(n,0);
6        stack<int> st;
7
8        for(int i = 0; i < n; i++) {
9            while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
10                ans[st.top()] = i - st.top();
11
12                st.pop();
13            }
14
15            st.push(i);
16        }
17
18        return ans;
19    }
20};