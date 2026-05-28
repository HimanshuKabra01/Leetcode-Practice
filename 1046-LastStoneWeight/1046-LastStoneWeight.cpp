// Last updated: 5/29/2026, 1:59:48 AM
1class Solution {
2public:
3    int lastStoneWeight(vector<int>& stones) {
4        priority_queue<int> pq;
5
6        for(int i = 0; i < stones.size(); i++) {
7            pq.push(stones[i]);
8        }
9
10        int ans = 0;
11        while(pq.size() > 1) {
12            int y = pq.top();
13            pq.pop();
14            int x = pq.top();
15            pq.pop();
16
17            if(x != y) {
18                pq.push(y - x);
19            }
20        }
21
22        if(pq.size() == 0) {
23            return 0;
24        } else {
25            return pq.top();
26        }
27    }
28};