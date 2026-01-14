// Last updated: 1/14/2026, 12:10:22 PM
1class Solution {
2public:
3    int firstUniqChar(string s) {
4        map<char, int> m;
5        int n = s.size();
6        queue<pair<char, int>> q;
7        int ans = -1;
8
9        for(int i = 0; i < n; i++) {
10            m[s[i]]++;
11            q.push({s[i], i});
12        }
13
14        while(!q.empty()) {
15            if(m[q.front().first] == 1) {
16                ans = q.front().second;
17                break;
18            }
19
20            q.pop();
21        }
22
23        return ans;
24    }
25};