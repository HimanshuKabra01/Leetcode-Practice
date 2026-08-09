// Last updated: 8/9/2026, 12:31:20 PM
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> ans;

        vector<vector<int>> adj(n);

        for(int i = 0; i < invocations.size(); i++) {
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }

        vector<bool> vis(n, false);
        queue<int> q;
        q.push(k);
        vis[k] = true;

        while(!q.empty()) {
            int u = q.front();

            q.pop();

            for(int v : adj[u]) {
                if(!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                } 
            }
        }

        bool possible = true;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                for(int v : adj[i]) {
                    if(vis[v]) {
                        possible = false;
                        break;
                    }
                }
            } 
        }

        if(!possible) {
            for(int i = 0; i < n; i++) {
                ans.push_back(i);
            }
        } else {
            for(int i = 0; i < n; i++) {
                if(!vis[i]) {
                    ans.push_back(i);
                }
            }
        }

        return ans;
    }
};