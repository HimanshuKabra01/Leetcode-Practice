// Last updated: 4/19/2026, 3:08:51 PM
1class Solution {
2public:
3    int firstStableIndex(vector<int>& nums, int k) {
4        int n = nums.size();
5        vector<int> maxi(n);
6        vector<int> mini(n);
7
8        maxi[0] = nums[0];
9        for(int i = 1; i < n; i++) {
10            if(nums[i] > maxi[i-1]) {
11                maxi[i] = nums[i];
12            } else {
13                maxi[i] = maxi[i-1];
14            }
15        }
16
17        mini[n-1] = nums[n-1];
18        for(int i = n-2; i >= 0; i--) {
19            if(nums[i] < mini[i+1]) {
20                mini[i] = nums[i];
21            } else {
22                mini[i] = mini[i+1];
23            }
24        }
25        int ans = -1;
26        for(int i = 0; i < n; i++) {
27            int score = maxi[i]-mini[i];
28
29            if(score <= k) {
30                ans = i;
31                break;
32            }
33        }
34
35        return ans;
36    }
37};