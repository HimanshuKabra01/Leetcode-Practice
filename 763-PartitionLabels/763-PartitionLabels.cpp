// Last updated: 7/21/2026, 3:22:32 PM
1class Solution {
2public:
3    vector<int> partitionLabels(string s) {
4        int n = s.length();
5        vector<int> ans;
6        vector<int> idx(26, INT_MIN);
7
8        for(int i = 0; i < n ; i++) {
9            if(i > idx[s[i]-'a']) {
10                idx[s[i]-'a'] = i;
11            }
12        }
13        
14        int end = 0;
15        int prevEnd = 0;
16        for(int i = 0; i < n; i++) {
17            if(idx[s[i]-'a'] > end) {
18                end = idx[s[i]-'a'];
19            }
20
21            if(i == end) {
22                ans.push_back(end+1-prevEnd);
23                prevEnd = end+1;
24            }
25        }
26
27        return ans;
28    }
29};