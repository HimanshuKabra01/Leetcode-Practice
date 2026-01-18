// Last updated: 1/18/2026, 10:33:51 AM
1class Solution {
2public:
3    int vowelConsonantScore(string s) {
4        int n = s.size();
5        int v = 0;
6        int c = 0;
7
8        for(int i = 0; i < n; i++) {
9            if(s[i] == 'a' || s[i] == 'i' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u') {
10                v++;
11            } else if(s[i] != ' ' && (s[i] != '1' && s[i] != '2' && s[i] != '3' && s[i] != '4' && s[i] != '5' && s[i] != '6' && s[i] != '7' && s[i] != '8' && s[i] != '9' && s[i] != '0')) {
12                c++;
13            }
14        }
15
16        if(c == 0) {
17            return 0;
18        }
19
20        int ans = v / c;
21
22        return ans;
23    }
24};