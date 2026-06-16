// Last updated: 6/17/2026, 12:09:25 AM
1class Solution {
2public:
3    void dfs(int u, int target, vector<vector<int>> &graph, vector<int> &path, vector<vector<int>> &ans) {
4        path.push_back(u);
5
6        if(u == target) ans.push_back(path);
7        else {
8            for(int v : graph[u]) {
9                dfs(v, target, graph, path, ans);
10            }
11        }
12
13        path.pop_back();
14    }
15    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
16        int n = graph.size();
17        vector<vector<int>> ans;
18
19        vector<int> path;
20
21        dfs(0, n-1, graph, path, ans);
22            
23        return ans;
24    }
25};