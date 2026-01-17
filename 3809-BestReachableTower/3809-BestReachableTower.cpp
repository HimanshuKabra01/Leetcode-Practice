// Last updated: 1/18/2026, 1:40:44 AM
1class Solution {
2public:
3    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
4        int n = towers.size();
5        vector<int> ans;
6        vector<vector<int>> reachable;
7        int quality = 0;
8
9        for(int i = 0; i < n; i++) {
10            int manhattan = abs(towers[i][0] - center[0]) + abs(towers[i][1] - center[1]);
11
12            if(manhattan <= radius) {
13                reachable.push_back(towers[i]);
14
15                if(quality < towers[i][2]) {
16                    quality = towers[i][2];
17                }
18            }
19        }
20
21        if(reachable.size() == 1) {
22            return {reachable[0][0], reachable[0][1]};
23        } else {
24            sort(reachable.begin(), reachable.end());
25            
26            for(int i = 0; i < reachable.size(); i++) {
27                if(reachable[i][2] == quality) {
28                    return {reachable[i][0], reachable[i][1]};
29                }
30            }
31        }
32
33        return {-1, -1};
34    }
35};