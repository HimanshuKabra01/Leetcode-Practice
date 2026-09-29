// Last updated: 9/30/2026, 12:25:59 AM
1class Solution {
2public:
3    string reorganizeString(string s) {
4        unordered_map<char, int> mp;
5        int n = s.length();
6
7        for(int i = 0; i < n; i++) {
8            mp[s[i]]++;
9        }
10
11        int mx = 0;
12        for(auto &x : mp) {
13            if(x.second > mx) {
14                mx = x.second;
15            }
16        }
17
18        if(mx > (n+1)/2) {
19            return "";
20        }
21
22        priority_queue<pair<int, char>> pq;
23
24        for(auto &x : mp) {
25            pq.push({x.second, x.first});
26        }
27
28        string ans = "";
29        int tf = 0;
30        char tc;
31        while(!pq.empty()) {
32            int freq = pq.top().first;
33            char c = pq.top().second;
34
35            pq.pop();
36
37            ans += c;
38            freq--;
39
40            if(tf != 0) {
41                pq.push({tf, tc});
42            }
43
44            if(freq > 0) {
45                tf = freq;
46                tc = c;
47            } else {
48                tf = 0;
49            }
50        }
51
52        return ans;
53    }
54};