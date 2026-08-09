// Last updated: 8/9/2026, 12:35:37 PM
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for(int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        vector<int> ans(n, INT_MAX);

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});
        ans[src] = 0;

        while(!pq.empty()) {
            vector<int> a = pq.top();
            int cost = a[0];
            int u = a[1];
            int stops = a[2];

            pq.pop();

            if(stops <= ans[u]) {
                ans[u] = stops;
            } else {
                continue;
            }

            if(u == dst) return cost;

            for(auto it : adj[u]) {
                int v = it.first;
                int wt = it.second;

                if(stops <= k) {
                    pq.push({cost+wt, v, stops+1});
                }
            }
        }

        return -1;
    }
};