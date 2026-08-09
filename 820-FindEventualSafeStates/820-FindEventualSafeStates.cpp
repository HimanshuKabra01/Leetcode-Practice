// Last updated: 8/9/2026, 12:35:31 PM
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      int n = graph.size();
      vector<vector<int>> adj(n);

      for(int u = 0; u < n; u++) {
        for(int v : graph[u]) {
            adj[v].push_back(u);
        }
      }

      vector<int> indegree(n);
      for(int u = 0; u < n; u++) {
        for(int v : adj[u]) {
            indegree[v]++;
        }
      }

      vector<int> ans;
      queue<int> q;

      for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
      }

      while(!q.empty()) {
        int curr = q.front();
        q.pop();
        ans.push_back(curr);

        for(int v : adj[curr]) {
            indegree[v]--;

            if(indegree[v] == 0) {
                q.push(v);
            }
        }
      }

      sort(ans.begin(), ans.end());

      return ans;
    }
};