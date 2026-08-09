// Last updated: 8/9/2026, 12:32:29 PM
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<long, long>>> adj(n);

        for(int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        vector<long long> dis(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        priority_queue<pair<long long, long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        pq.push({0, 0});
        dis[0] = 0;
        ways[0] = 1;

        while(!pq.empty()) {
            long long dist = pq.top().first;
            long long u = pq.top().second;

            pq.pop();
            for(auto it : adj[u]) {
                long long v = it.first;
                long long wt = it.second;

                if(dist + wt < dis[v]) {
                    dis[v] = dist+wt;
                    pq.push({dist+wt, v});
                    ways[v] = ways[u];
                } else if(dist + wt == dis[v]) {
                    ways[v] = (ways[v] +ways[u]) % MOD;
                }
            }
        }

        long long ans = ways[n-1];

        return (ans % MOD);
    }
};