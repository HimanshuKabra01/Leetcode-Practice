// Last updated: 5/12/2026, 12:06:28 PM
1class Solution {
2public:
3    void dfs(vector<vector<int>> &adj, vector<bool> &vis, int u) {
4        vis[u] = true;
5
6        for(int v : adj[u]) {
7            if(!vis[v]) {
8                dfs(adj, vis, v);
9            }
10        }
11    }
12    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
13        int V = edges.size();
14
15        vector<vector<int>> adj(V+1);
16        vector<int> ans;
17
18        for(int i = 0; i < V; i++) {
19            vector<bool> vis(V+1, false);
20
21            dfs(adj, vis, edges[i][0]);
22
23            if(!vis[edges[i][1]]) {
24                adj[edges[i][0]].push_back(edges[i][1]);
25                adj[edges[i][1]].push_back(edges[i][0]);
26            } else {
27                ans.push_back(edges[i][0]);
28                ans.push_back(edges[i][1]);
29                break;
30            }
31        }
32
33        return ans; 
34    }
35};