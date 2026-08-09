// Last updated: 8/9/2026, 12:34:09 PM
class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool> pre(26, false);
        vector<int> freq(26, 0);
        stack<char> st;
        string ans = "";

        for(int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }

        for(int i = 0; i < s.length(); i++) {
            char c = s[i];

            freq[c-'a']--;

            if (pre[c-'a']) {
                continue;
            }

            while(!st.empty() && st.top() >= s[i] && freq[st.top()-'a'] > 0) {
                pre[st.top()-'a'] = false;
                st.pop();
            }

            st.push(c);
            pre[c-'a'] = true;
        }

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};