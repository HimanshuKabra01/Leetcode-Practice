// Last updated: 9/27/2026, 12:47:35 AM
1class Solution {
2public:
3    string evaluate(string s, vector<vector<string>>& knowledge) {
4        map<string, string> m;
5
6        for(int i = 0; i < knowledge.size(); i++) {
7            m[knowledge[i][0]] = knowledge[i][1];
8        }
9
10        for(int i = 0; i < s.length(); i++) {
11            if(s[i] == '(') {
12                int st = i+1;
13                while(i < s.length() && s[i] != ')') {
14                    i++;
15                }
16
17                string key = s.substr(st, i-st);
18                int value;
19
20                if(m.find(key) != m.end()) {
21                    s.replace(st-1, key.length()+2, m[key]);
22                    value = m[key].length();
23                } else {
24                    s.replace(st-1, key.length()+2, "?");
25                    value = 1;
26                }
27
28                i = st - 2 + value;
29            }
30        }
31
32        return s;
33    }
34};