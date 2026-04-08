// Last updated: 4/8/2026, 10:48:33 PM
1class Solution {
2public:
3    int minEatingSpeed(vector<int>& piles, int h) {
4        int n = piles.size();
5        int end = piles[0];
6
7        for(int i = 1; i < n; i++) {
8            if(piles[i] > end) {
9                end = piles[i];
10            }
11        }
12
13        int st = 1;
14
15        int ans = 0;
16        while(st <= end) {
17            double mid = st + (end-st)/2;
18
19            long long time = 0;
20
21            for(int i = 0; i < piles.size(); i++) {
22                time += ceil(piles[i]/mid);
23            }
24
25            if(time <= h) {
26                ans = mid;
27                end = mid - 1;
28            } else {
29                st = mid + 1;
30            }
31        }
32
33        return ans;
34    }
35};