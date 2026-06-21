// Last updated: 6/22/2026, 1:38:42 AM
1class Solution {
2public:
3    int countPaths(int n, vector<vector<int>>& roads) {
4        const int MOD = 1e9 + 7;
5        vector<vector<pair<long, long>>> adj(n);
6
7        for(int i = 0; i < roads.size(); i++) {
8            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
9            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
10        }
11
12        vector<long long> dis(n, LLONG_MAX);
13        vector<long long> ways(n, 0);
14
15        priority_queue<pair<long long, long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
16        pq.push({0, 0});
17        dis[0] = 0;
18        ways[0] = 1;
19
20        while(!pq.empty()) {
21            long long dist = pq.top().first;
22            long long u = pq.top().second;
23
24            pq.pop();
25            for(auto it : adj[u]) {
26                long long v = it.first;
27                long long wt = it.second;
28
29                if(dist + wt < dis[v]) {
30                    dis[v] = dist+wt;
31                    pq.push({dist+wt, v});
32                    ways[v] = ways[u];
33                } else if(dist + wt == dis[v]) {
34                    ways[v] = (ways[v] +ways[u]) % MOD;
35                }
36            }
37        }
38
39        long long ans = ways[n-1];
40
41        return (ans % MOD);
42    }
43};