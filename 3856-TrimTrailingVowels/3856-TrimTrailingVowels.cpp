// Last updated: 3/2/2026, 2:03:59 AM
1class Solution {
2public:
3    string trimTrailingVowels(string s) {
4        unordered_set<char> st;
5
6        st.insert('a');
7        st.insert('e');
8        st.insert('i');
9        st.insert('o');
10        st.insert('u');
11
12        string ans = "";
13
14        while(s.length()){
15            int len = s.size();
16
17            char last = s[len - 1];
18
19            if(st.count(last)) {
20                s.resize(len-1);
21                continue;
22            } else {
23                ans += s;
24                break;
25            }
26        }
27
28        return ans;
29    }
30};