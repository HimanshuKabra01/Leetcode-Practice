// Last updated: 6/15/2026, 1:21:40 AM
1class Solution {
2public:
3    void dfs(vector<vector<int>> &graph, int u, bool &ans, vector<int> &vis, int col) {
4        if(!ans) return;
5
6        int op;
7        if(col == 1) op = 0;
8        else if(col == 0) op = 1;
9
10        vis[u] = op;
11
12        for(int v : graph[u]) {
13            if(vis[v] == -1) {
14                dfs(graph, v, ans, vis, vis[u]);
15            } else if(vis[v] == op) {
16                ans = false;
17                return;
18            }
19        }
20    }
21    bool isBipartite(vector<vector<int>>& graph) {
22        int V = graph.size();
23
24        bool ans = true;
25        vector<int> vis(V, -1);
26        for(int i = 0; i < V; i++) {
27            if(vis[i] != -1) continue;
28
29            dfs(graph, i, ans, vis, 1);
30        }
31
32        if(!ans) return false;
33        return true;
34    }
35};