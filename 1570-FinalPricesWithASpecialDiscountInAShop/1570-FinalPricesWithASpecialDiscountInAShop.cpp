// Last updated: 8/9/2026, 12:33:17 PM
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && st.top() > prices[i]) {
                st.pop();
            }

            if(st.empty()) {
                ans[i] = prices[i];
            } else {
                ans[i] = prices[i] - st.top();
            }

            st.push(prices[i]);
        }

        return ans;
    }
};