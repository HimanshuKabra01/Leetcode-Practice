// Last updated: 3/26/2026, 11:18:22 PM
1class Solution {
2public:
3    bool dfs(int u, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>> &adj, stack<int> &s) {
4        vis[u] = true;
5        recPath[u] = true;
6
7        for(int v : adj[u]) {
8            if(!vis[v]) {
9                if (dfs(v, vis, recPath, adj, s)) return true;
10            } else if(recPath[v]) {
11                return true;
12            }
13        }
14
15        s.push(u);
16        recPath[u] = false;
17        return false;
18    }
19
20    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
21        vector<int> ans;
22        stack<int> s;
23        vector<vector<int>> adj(numCourses);
24
25        for(auto &p : prerequisites) {
26            int a = p[0];
27            int b = p[1];
28
29            adj[b].push_back(a);
30        }
31
32        vector<bool> vis(numCourses, false);
33        vector<bool> recPath(numCourses, false);
34
35        bool possible = true;
36
37        for(int i = 0; i < numCourses; i++) {
38            if(!vis[i]) {
39                if(dfs(i, vis, recPath, adj, s)){
40                    possible = false;
41                }
42            }
43        }
44
45        if(!possible) {
46            return {};
47        }
48
49        while(!s.empty()) {
50            int elem = s.top();
51            s.pop();
52
53            ans.push_back(elem);
54        }
55
56        return ans;
57    }
58};