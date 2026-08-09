// Last updated: 8/9/2026, 12:33:39 PM
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        for(int i = 0; i < n - 1; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            int x2 = points[i+1][0];
            int y2 = points[i+1][1];

            ans += max(abs(x2-x1), abs(y2-y1));
        }

        return ans;
    }
};