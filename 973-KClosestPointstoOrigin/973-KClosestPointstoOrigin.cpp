// Last updated: 6/6/2026, 12:58:58 AM
1class Solution {
2public:
3    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
4        vector<vector<int>> ans;
5
6        int n = points.size();
7
8        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<pair<double, vector<int>>>> pq;
9        for(int i = 0; i < n; i++) {
10            int x = points[i][0];
11            int y = points[i][1];
12
13            double dist = sqrt(x*x + y*y);
14
15            pq.push({dist, points[i]});
16        }
17
18        int count = 0;
19        while(!pq.empty()) {
20            vector<int> req = pq.top().second;
21            pq.pop();
22
23            count++;
24
25            if(count == k) {
26                ans.push_back(req);
27                break;
28            }
29
30            ans.push_back(req);
31        }
32
33        return ans;
34    }
35};