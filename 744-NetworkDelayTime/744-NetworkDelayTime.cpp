// Last updated: 8/9/2026, 12:36:15 PM
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);

        for(int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for(auto it : adj[u]) {
                int v = it.first;
                int wt = it.second;
                if(dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;

                    pq.push({dist[v], v});
                }
            }
        }

        int ans = 0;
        for(int i = 1; i < n+1; i++) {
            if(dist[i] == INT_MAX) {
                return -1;
            }

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};