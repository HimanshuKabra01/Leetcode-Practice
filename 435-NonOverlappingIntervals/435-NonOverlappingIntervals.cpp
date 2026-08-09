// Last updated: 8/9/2026, 12:37:28 PM
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) {
            return 0;
        }

        int ans = 0;

        sort(intervals.begin(), intervals.end());

        int last = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++) {
            int st = intervals[i][0];
            int end = intervals[i][1];

            if(st < last) {
                ans++;

                last = min(last, end);
            } else {
                last = end;
            }
        }

        return ans;
    }
};