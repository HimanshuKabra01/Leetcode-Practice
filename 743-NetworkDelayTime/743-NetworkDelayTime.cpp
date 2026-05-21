// Last updated: 5/21/2026, 7:30:07 PM
1class Solution {
2public:
3    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
4        vector<vector<pair<int, int>>> adj(n+1);
5
6        for(int i = 0; i < times.size(); i++) {
7            adj[times[i][0]].push_back({times[i][1], times[i][2]});
8        }
9
10        vector<int> dist(n+1, INT_MAX);
11        dist[k] = 0;
12
13        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
14        pq.push({0, k});
15
16        while(!pq.empty()) {
17            int u = pq.top().second;
18            pq.pop();
19
20            for(auto it : adj[u]) {
21                int v = it.first;
22                int wt = it.second;
23                if(dist[u] + wt < dist[v]) {
24                    dist[v] = dist[u] + wt;
25
26                    pq.push({dist[v], v});
27                }
28            }
29        }
30
31        int ans = 0;
32        for(int i = 1; i < n+1; i++) {
33            if(dist[i] == INT_MAX) {
34                return -1;
35            }
36
37            ans = max(ans, dist[i]);
38        }
39
40        return ans;
41    }
42};