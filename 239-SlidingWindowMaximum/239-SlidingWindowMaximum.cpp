// Last updated: 1/16/2026, 11:31:39 AM
1class Solution {
2public:
3    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
4       int n = nums.size();
5
6        deque<int> dq;
7        vector<int> ans;
8
9        for(int i = 0; i < k; i++) {
10          while(!dq.empty() && nums[dq.back()] <= nums[i]) {
11            dq.pop_back();
12          }
13
14          dq.push_back(i); 
15        }
16
17        for(int i = k; i < n; i++) {
18            ans.push_back(nums[dq.front()]);
19
20            while(!dq.empty() && dq.front() <= i - k) {
21                dq.pop_front();
22            }
23
24            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
25                dq.pop_back();
26            }
27
28            dq.push_back(i);
29        }
30
31        ans.push_back(nums[dq.front()]);
32
33        return ans;
34    }
35};