// Last updated: 8/9/2026, 12:38:58 PM
class Solution {
public:
    bool dfs(int u, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>> &adj, stack<int> &s) {
        vis[u] = true;
        recPath[u] = true;

        for(int v : adj[u]) {
            if(!vis[v]) {
                if (dfs(v, vis, recPath, adj, s)) return true;
            } else if(recPath[v]) {
                return true;
            }
        }

        s.push(u);
        recPath[u] = false;
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        stack<int> s;
        vector<vector<int>> adj(numCourses);

        for(auto &p : prerequisites) {
            int a = p[0];
            int b = p[1];

            adj[b].push_back(a);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> recPath(numCourses, false);

        bool possible = true;

        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                if(dfs(i, vis, recPath, adj, s)){
                    possible = false;
                }
            }
        }

        if(!possible) {
            return {};
        }

        while(!s.empty()) {
            int elem = s.top();
            s.pop();

            ans.push_back(elem);
        }

        return ans;
    }
};