// Last updated: 11/6/2026, 1:36:17 AM
1class Solution {
2public:
3    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
4        int n = arr1.size();
5        int m = arr2.size();
6
7        int ans = 0;
8
9        for(int i = 0; i < n; i++) {
10            bool possible = false;
11            for(int j = 0; j < m; j++) {
12                if(abs(arr1[i]-arr2[j]) <= d) {
13                    possible = true;
14                }
15            }
16
17            if(!possible) {
18                ans++;
19            }
20        }
21
22        return ans;
23    }
24};