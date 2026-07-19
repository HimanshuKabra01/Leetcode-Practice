// Last updated: 7/19/2026, 4:11:10 PM
1class Solution {
2public:
3    string removeDuplicateLetters(string s) {
4         vector<bool> pre(26, false);
5        vector<int> freq(26, 0);
6        stack<char> st;
7        string ans = "";
8
9        for(int i = 0; i < s.length(); i++) {
10            freq[s[i] - 'a']++;
11        }
12
13        for(int i = 0; i < s.length(); i++) {
14            char c = s[i];
15
16            freq[c-'a']--;
17
18            if (pre[c-'a']) {
19                continue;
20            }
21
22            while(!st.empty() && st.top() >= s[i] && freq[st.top()-'a'] > 0) {
23                pre[st.top()-'a'] = false;
24                st.pop();
25            }
26
27            st.push(c);
28            pre[c-'a'] = true;
29        }
30
31        while(!st.empty()) {
32            ans += st.top();
33            st.pop();
34        }
35
36        reverse(ans.begin(), ans.end());
37
38        return ans;
39    }
40};