// Last updated: 7/23/2026, 4:26:00 PM
1class Solution {
2public:
3    int romanToInt(string s) {
4        map<char, int> mp;
5
6        mp['I'] = 1;
7        mp['V'] = 5;
8        mp['X'] = 10;
9        mp['L'] = 50;
10        mp['C'] = 100;
11        mp['D'] = 500;
12        mp['M'] = 1000;
13
14        int ans = 0;
15
16        for(int i = 0; i < s.size(); i++) {
17            if(i < s.size()-1 && mp[s[i]] < mp[s[i+1]]) {
18                ans -= mp[s[i]];
19            } else {
20                ans += mp[s[i]];
21            }
22        }
23
24        return ans;
25    }
26};