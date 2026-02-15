// Last updated: 2/15/2026, 10:00:44 AM
1class Solution {
2public:
3    vector<int> toggleLightBulbs(vector<int>& bulbs) {
4        vector<int> ans;
5        map<int, int> m;
6
7        for(int i = 0; i < bulbs.size(); i++) {
8            m[bulbs[i]]++;
9        }
10
11        for(auto &entry : m) {
12            if(entry.second % 2 != 0) {
13                ans.push_back(entry.first);
14            }
15        }
16
17        return ans;
18    }
19};