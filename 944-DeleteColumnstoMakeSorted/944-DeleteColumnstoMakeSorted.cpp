// Last updated: 12/20/2025, 11:05:31 AM
1class Solution {
2public:
3    int minDeletionSize(vector<string>& strs) {
4        int n = strs.size();
5        int ans = 0;
6
7        for(int i = 0; i < strs[0].size(); i++) {
8            for(int j = 0; j < n-1; j++) {
9                if(strs[j][i] > strs[j+1][i]) {
10                    ans++;
11                    break;
12                }
13            }
14        }
15
16        return ans;
17    }
18};