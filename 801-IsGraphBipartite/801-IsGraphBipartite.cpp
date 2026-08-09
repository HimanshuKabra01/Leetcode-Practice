// Last updated: 8/9/2026, 12:35:39 PM
class Solution {
public:
    void dfs(vector<vector<int>> &graph, int u, bool &ans, vector<int> &vis, int col) {
        if(!ans) return;

        int op;
        if(col == 1) op = 0;
        else if(col == 0) op = 1;

        vis[u] = op;

        for(int v : graph[u]) {
            if(vis[v] == -1) {
                dfs(graph, v, ans, vis, vis[u]);
            } else if(vis[v] == op) {
                ans = false;
                return;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();

        bool ans = true;
        vector<int> vis(V, -1);
        for(int i = 0; i < V; i++) {
            if(vis[i] != -1) continue;

            dfs(graph, i, ans, vis, 1);
        }

        if(!ans) return false;
        return true;
    }
};