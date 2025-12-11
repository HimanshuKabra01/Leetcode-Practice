// Last updated: 12/11/2025, 10:57:38 PM
1class Solution {
2public:
3    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
4        if(intervals.size() == 0) {
5            return 0;
6        }
7
8        int ans = 0;
9
10        sort(intervals.begin(), intervals.end());
11
12        int last = intervals[0][1];
13
14        for(int i = 1; i < intervals.size(); i++) {
15            int st = intervals[i][0];
16            int end = intervals[i][1];
17
18            if(st < last) {
19                ans++;
20
21                last = min(last, end);
22            } else {
23                last = end;
24            }
25        }
26
27        return ans;
28    }
29};