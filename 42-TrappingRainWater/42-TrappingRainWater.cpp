// Last updated: 1/10/2026, 7:06:39 PM
1class Solution {
2public:
3    int trap(vector<int>& height) {
4        int n = height.size();
5
6        int st = 0;
7        int end = n - 1;
8
9        int ans = 0;
10
11        int leftMax = height[0];
12        int rightMax = height[n-1];
13
14        while(st < end) {
15           if(height[st] < height[end]) {
16            if(height[st] > leftMax) {
17                leftMax = height[st];
18            }
19
20            ans += leftMax - height[st];
21            st++;
22           } else {
23            if(height[end] > rightMax) {
24                rightMax = height[end];
25            }
26
27            ans += rightMax - height[end];
28            end--;
29           }
30        }
31
32        return ans;
33    }
34};