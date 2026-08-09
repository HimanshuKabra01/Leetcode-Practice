// Last updated: 8/9/2026, 12:35:34 PM
class Solution {
public:
    void dfs(int u, int target, vector<vector<int>> &graph, vector<int> &path, vector<vector<int>> &ans) {
        path.push_back(u);

        if(u == target) ans.push_back(path);
        else {
            for(int v : graph[u]) {
                dfs(v, target, graph, path, ans);
            }
        }

        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;

        vector<int> path;

        dfs(0, n-1, graph, path, ans);
            
        return ans;
    }
};