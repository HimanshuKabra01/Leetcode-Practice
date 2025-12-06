// Last updated: 12/6/2025, 5:29:16 PM
1class Solution {
2public:
3    vector<int> finalPrices(vector<int>& prices) {
4        int n = prices.size();
5        vector<int> ans(n);
6        stack<int> st;
7
8        for(int i = n-1; i >= 0; i--) {
9            while(!st.empty() && st.top() > prices[i]) {
10                st.pop();
11            }
12
13            if(st.empty()) {
14                ans[i] = prices[i];
15            } else {
16                ans[i] = prices[i] - st.top();
17            }
18
19            st.push(prices[i]);
20        }
21
22        return ans;
23    }
24};