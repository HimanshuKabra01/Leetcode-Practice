// Last updated: 5/17/2026, 12:16:29 PM
1class Solution {
2public:
3    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
4      int n = graph.size();
5      vector<vector<int>> adj(n);
6
7      for(int u = 0; u < n; u++) {
8        for(int v : graph[u]) {
9            adj[v].push_back(u);
10        }
11      }
12
13      vector<int> indegree(n);
14      for(int u = 0; u < n; u++) {
15        for(int v : adj[u]) {
16            indegree[v]++;
17        }
18      }
19
20      vector<int> ans;
21      queue<int> q;
22
23      for(int i = 0; i < n; i++) {
24        if(indegree[i] == 0) {
25            q.push(i);
26        }
27      }
28
29      while(!q.empty()) {
30        int curr = q.front();
31        q.pop();
32        ans.push_back(curr);
33
34        for(int v : adj[curr]) {
35            indegree[v]--;
36
37            if(indegree[v] == 0) {
38                q.push(v);
39            }
40        }
41      }
42
43      sort(ans.begin(), ans.end());
44
45      return ans;
46    }
47};