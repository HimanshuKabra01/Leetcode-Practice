// Last updated: 11/16/2025, 11:47:29 AM
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        for(int i = 0; i < n; i++) {
            int st = intervals[i][0];
            int end = intervals[i][1];

            while(i < n - 1 && end >= intervals[i+1][0]) {
                end = max(end, intervals[i+1][1]);

                i++;
            }

            ans.push_back({st, end});
        }

        return ans;
    }
};