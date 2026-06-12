// Last updated: 6/13/2026, 12:34:40 AM
1class KthLargest {
2public:
3    priority_queue<int, vector<int>, greater<int>> pq;
4    int kth = 0;
5    KthLargest(int k, vector<int>& nums) {
6        kth = k;
7        for(int i = 0; i < nums.size(); i++) {
8            add(nums[i]);
9        }
10    }
11    
12    int add(int val) {
13        pq.push(val);
14
15        if(pq.size() > kth) {
16            pq.pop();
17        }
18
19        return pq.top();
20    }
21};
22
23/**
24 * Your KthLargest object will be instantiated and called as such:
25 * KthLargest* obj = new KthLargest(k, nums);
26 * int param_1 = obj->add(val);
27 */