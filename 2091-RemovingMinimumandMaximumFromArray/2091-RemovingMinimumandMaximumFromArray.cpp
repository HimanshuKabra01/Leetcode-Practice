// Last updated: 8/30/2026, 12:22:26 PM
1class Solution {
2public:
3    int minimumDeletions(vector<int>& nums) {
4        int n = nums.size();
5
6        int mn = nums[0];
7        int mx = nums[0];
8
9        int id = 0;
10        int jd = 0;
11
12        for(int i = 0; i < n; i++) {
13            if(nums[i] > mx) {
14                mx = nums[i];
15                id = i;
16            } else if(nums[i] < mn) {
17                mn = nums[i];
18                jd = i;
19            }
20        }
21
22        int a = 0;
23        int b = 0;
24        int c = 0;
25
26        if(jd > id) {
27            a = jd+1;
28            b = n-id;
29            c = id+1+n-jd;
30        } else {
31            a = id+1;
32            b = n-jd;
33            c = jd+1+n-id;
34        }
35
36        return min(a, min(b, c));
37    }
38};