// Last updated: 3/26/2026, 1:53:45 AM
1class Solution {
2public:
3    bool dfs(int u, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>> &adj) {
4        vis[u] = true;
5        recPath[u] = true;
6
7        for(int v : adj[u]) {
8            if(!vis[v]) {
9                if (dfs(v, vis, recPath, adj)) return true;
10            } else if(recPath[v]) {
11                return true;
12            }
13        }
14
15        recPath[u] = false;
16        return false;
17    }
18
19    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
20        vector<vector<int>> adj(numCourses);
21
22        for(auto &p : prerequisites) {
23            int a = p[0];
24            int b = p[1];
25
26            adj[b].push_back(a);
27        }
28
29        vector<bool> vis(numCourses, false);
30        vector<bool> recPath(numCourses, false);
31
32        for(int i = 0; i < numCourses; i++) {
33            if(!vis[i]) {
34                if(dfs(i, vis, recPath, adj)) {
35                    return false;
36                }
37            }
38        }
39
40        return true;
41    }
42};