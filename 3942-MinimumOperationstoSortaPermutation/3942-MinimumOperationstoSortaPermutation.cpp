// Last updated: 5/29/2026, 1:11:47 AM
1class Solution {
2public:
3    int passwordStrength(string password) {
4        int ans = 0;
5        unordered_set<char> st;
6
7        for(int i = 0; i < password.size(); i++) {
8            if(st.count(password[i])) continue;
9
10            if(password[i] >= 'a' && password[i] <= 'z') {
11                ans += 1;
12                st.insert(password[i]);
13            } else if(password[i] >= 'A' && password[i] <= 'Z') {
14                ans += 2;
15                st.insert(password[i]);
16            } else if(password[i] >= '0' && password[i] <= '9') {
17                ans += 3;
18                st.insert(password[i]);
19            } else if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$'){
20                ans += 5;
21                st.insert(password[i]);
22            }
23        }
24
25        return ans;
26    }
27};