// Last updated: 2/22/2026, 2:28:18 PM
1class Solution {
2public:
3    int scoreDifference(vector<int>& nums) {
4        int n = nums.size();
5
6        int scoreA = 0;
7        int scoreB = 0;
8
9        bool a = true;
10        bool b = false;
11
12        for(int i = 0; i < n; i++) {
13            if(nums[i] % 2 != 0) {
14                if(a) {
15                    b = true;
16                    a = false;
17                } else {
18                    b = false;
19                    a = true;
20                }
21            }
22
23            if((i + 1) % 6 == 0) {
24                if(a) {
25                    b = true;
26                    a = false;
27                } else {
28                    b = false;
29                    a = true;
30                }
31            }
32
33            if(a) {
34                scoreA += nums[i];
35            } else {
36                scoreB += nums[i];
37            }
38        }
39
40        return scoreA - scoreB;
41    }
42};