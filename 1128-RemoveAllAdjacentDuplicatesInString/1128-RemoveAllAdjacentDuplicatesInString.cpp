// Last updated: 8/9/2026, 12:34:10 PM
class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        stack<char> st;
        string ans = "";

        for(int i = 0; i < n; i++) {
            if(!st.empty()) {
                if(st.top() == s[i]) {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            } else {
                st.push(s[i]);
            }
        }

        while(st.size() != 0) {
            ans += st.top();

            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};