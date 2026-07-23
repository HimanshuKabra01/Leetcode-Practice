// Last updated: 7/23/2026, 6:35:05 PM
1class Solution {
2public:
3    vector<vector<int>> generate(int n) {
4        vector<vector<int>> ans(n);
5
6        if(n == 1) {
7            return {{1}};
8        } else {
9            int i = 0;
10            ans[i].push_back(1);
11            i++;
12
13            while(i < n){
14                ans[i].push_back(1);
15
16                for(int j = 0; j < i-1; j++) {
17                    int curr = ans[i-1][j] + ans[i-1][j+1];
18
19                    ans[i].push_back(curr);
20                }
21
22                ans[i].push_back(1);
23
24                i++;
25            }
26        }
27
28        return ans;
29    }
30};