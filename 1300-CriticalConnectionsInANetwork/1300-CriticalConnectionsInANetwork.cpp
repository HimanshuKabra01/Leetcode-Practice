// Last updated: 8/9/2026, 12:33:53 PM
class Solution {
public:
    int timer = 1;
    void dfs(int u, int par, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &tin, vector<int> &low, vector<vector<int>> &ans) {
        vis[u] = true;
        tin[u] = low[u] = timer;
        timer++;

        for(int v : adj[u]) {
            if(!vis[v]) {
                dfs(v, u, adj, vis, tin, low, ans);
                low[u] = min(low[u], low[v]);

                if(low[v] > tin[u]) {
                    ans.push_back({u, v});
                }
            } else if(vis[v] && v != par) {
                if(tin[v] < low[u]) {
                    low[u] = tin[v];
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for(int i = 0; i < connections.size(); i++) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        vector<bool> vis(n, false);
        vector<int> tin(n);
        vector<int> low(n);

        vector<vector<int>> ans;
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, -1, adj, vis, tin, low, ans);
            }
        }

        return ans;
    }   
};