// Last updated: 2/15/2026, 1:46:38 AM
1class Solution {
2public:
3    int prefixConnected(vector<string>& words, int k) {
4        int n = words.size();
5        int ans = 0;
6
7        if(n == 1) {
8            return 0;
9        }
10
11        sort(words.begin(), words.end());
12
13        vector<string> focus;
14
15        for(int i = 0; i < n; i++) {
16            string s = words[i];
17
18            if(s.size() < k) {
19                continue;
20            }
21
22            s.resize(k); 
23
24            focus.push_back(s);
25        }
26
27        int i = 0;
28        while(i < focus.size()) {
29            int j = i + 1;
30
31            while(j < focus.size() && focus[j] == focus[i]) {
32                j++;
33            }
34
35            if(j-i >= 2) {
36                ans++;
37            }
38
39            i = j;  
40        }
41
42        return ans;
43    }
44};