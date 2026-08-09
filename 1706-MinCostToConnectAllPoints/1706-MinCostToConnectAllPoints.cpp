// Last updated: 8/9/2026, 12:33:02 PM
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<vector<pair<int, int>>> adj(n);

        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                int wt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }

        vector<bool> vis(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        int ans = 0;

        while(!pq.empty()) {
            int dis = pq.top().first;
            int u = pq.top().second;

            pq.pop();
            if(vis[u]) continue;

            vis[u] = true;
            ans += dis;

            for(auto it : adj[u]) {
                int v = it.first;
                int wt = it.second;

                if(!vis[v]) {
                    pq.push({wt, v});
                }
            }
        }

        return ans;
    }
};