// Last updated: 1/11/2026, 11:04:20 AM
1class Solution {
2public:
3    int residuePrefixes(string s) {
4        unordered_set<char> st;
5        int ans = 0;
6        int n = s.size();
7
8        string prefix = "";
9        int dist = 0;
10
11        for(int i = 0; i < n; i++) {
12            prefix += s[i];
13
14            if(st.find(s[i]) == st.end()) {
15                dist++;
16
17                st.insert(s[i]);
18            }
19
20            int resi = (prefix.size() % 3);
21
22            if(dist == resi) {
23                ans++;
24            }
25        }
26
27        return ans;
28    }
29};