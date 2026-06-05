// Last updated: 6/5/2026, 5:44:58 PM
1class Solution {
2public:
3    int findKthLargest(vector<int>& nums, int k) {
4        int n = nums.size();
5
6        priority_queue<int> pq;
7
8        for(int i = 0; i < n; i++) {
9            pq.push(nums[i]);
10        }
11        int count = 0;
12        int ans = 0;
13
14        while(!pq.empty()) {
15            int num = pq.top();
16
17            pq.pop();
18            count++;
19
20            if(count == k) {
21                ans = num;
22                break;
23            }
24        }
25
26        return ans;
27    }
28};