// Last updated: 6/19/2026, 7:51:17 PM
1class Solution {
2public:
3    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
4        vector<vector<pair<int, int>>> adj(n);
5
6        for(int i = 0; i < flights.size(); i++) {
7            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
8        }
9
10        vector<int> ans(n, INT_MAX);
11
12        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
13        pq.push({0, src, 0});
14        ans[src] = 0;
15
16        while(!pq.empty()) {
17            vector<int> a = pq.top();
18            int cost = a[0];
19            int u = a[1];
20            int stops = a[2];
21
22            pq.pop();
23
24            if(stops <= ans[u]) {
25                ans[u] = stops;
26            } else {
27                continue;
28            }
29
30            if(u == dst) return cost;
31
32            for(auto it : adj[u]) {
33                int v = it.first;
34                int wt = it.second;
35
36                if(stops <= k) {
37                    pq.push({cost+wt, v, stops+1});
38                }
39            }
40        }
41
42        return -1;
43    }
44};