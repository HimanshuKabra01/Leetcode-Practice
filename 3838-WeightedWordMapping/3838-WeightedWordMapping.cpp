// Last updated: 2/14/2026, 10:38:10 PM
1class Solution {
2public:
3    string mapWordWeights(vector<string>& words, vector<int>& weights) {
4        int n = words.size();
5        string ans = "";
6
7        for(int i = 0; i < n; i++) {
8            string s = words[i];
9            int sum = 0;
10
11            for(int j = 0; j < s.size(); j++) {
12                sum += weights[s[j] - 'a'];
13            }
14
15            int wm = sum % 26;
16
17            ans += 'z' - wm;
18        }
19
20        return ans;
21    }
22};