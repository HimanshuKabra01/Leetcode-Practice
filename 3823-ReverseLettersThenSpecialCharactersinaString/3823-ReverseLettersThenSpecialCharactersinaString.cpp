// Last updated: 1/31/2026, 10:37:11 PM
1class Solution {
2public:
3    string reverseByType(string s) {
4        int n = s.size();
5
6        string letters = "";
7        string character = "";
8        string ans = "";
9
10        for(int i = 0; i < n; i++) {
11            if(isalnum(s[i])) {
12                letters += s[i];
13            } else {
14                character += s[i];
15            }
16        }
17
18        reverse(letters.begin(), letters.end());
19        reverse(character.begin(), character.end());
20
21        int m = letters.size();
22        int o = character.size();
23
24        int st = 0;
25        int end = 0;
26
27        for(int i = 0; i < n; i++) {
28            if(isalnum(s[i])) {
29                if(st > m) continue;
30                else {
31                    ans += letters[st];
32
33                    st++;
34                }
35            } else {
36                if(end > o) continue;
37                else {
38                    ans += character[end];
39
40                    end++;
41                }
42            }
43        }
44
45        return ans;
46    }
47};