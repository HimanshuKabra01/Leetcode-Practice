// Last updated: 4/5/2026, 3:18:12 PM
1class Solution {
2public:
3    int mirrorFrequency(string s) {
4        unordered_map<char, int> mp;
5        unordered_set<char> st;
6
7        for(int i = 0; i < s.size(); i++) {
8            mp[s[i]]++;
9        }
10
11        int ans = 0;
12        for (auto &it : mp) {
13            char ch = it.first;
14            char m;
15
16            if (st.find(ch) != st.end()) continue;
17
18            if (!isdigit(ch)) {
19                m = 'z' - (ch - 'a');
20            } else {
21                m = '9' - (ch - '0');
22            }
23
24            st.insert(ch);
25            st.insert(m);
26
27            int freqM = 0;
28            if(mp.count(m)) {
29                freqM = mp[m];
30            }
31
32            ans += abs(mp[ch]-freqM);
33        }
34
35        return ans;
36    }
37};