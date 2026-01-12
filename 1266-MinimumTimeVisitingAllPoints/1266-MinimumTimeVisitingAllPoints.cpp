// Last updated: 1/12/2026, 6:14:18 PM
1class Solution {
2public:
3    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
4        int n = points.size();
5        int ans = 0;
6
7        for(int i = 0; i < n - 1; i++) {
8            int x1 = points[i][0];
9            int y1 = points[i][1];
10            int x2 = points[i+1][0];
11            int y2 = points[i+1][1];
12
13            ans += max(abs(x2-x1), abs(y2-y1));
14        }
15
16        return ans;
17    }
18};