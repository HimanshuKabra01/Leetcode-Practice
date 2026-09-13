// Last updated: 9/14/2026, 1:40:42 AM
1class Solution {
2public:
3    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
4        int n = img1.size();
5
6        vector<vector<int>> a;
7        vector<vector<int>> b;
8
9        for(int i = 0; i < n; i++) {
10            for(int j = 0; j < n; j++) {
11                if(img1[i][j] == 1) {
12                    a.push_back({i, j});
13                }
14
15                if(img2[i][j] == 1) {
16                    b.push_back({i, j});
17                }
18            }
19        }
20
21        map<pair<int, int>, int> mp;
22        int ans = 0;
23
24        for(auto &pa : a) {
25            for(auto &pb: b) {
26                int x = pa[0] - pb[0];
27                int y = pa[1] - pb[1];
28
29                mp[{x, y}]++;
30
31                ans = max(ans, mp[{x,y}]);
32            }
33        }
34
35        return ans;
36    }
37};