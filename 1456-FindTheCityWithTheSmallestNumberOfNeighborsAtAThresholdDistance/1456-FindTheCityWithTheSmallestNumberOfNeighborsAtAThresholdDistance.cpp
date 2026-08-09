// Last updated: 8/9/2026, 12:33:31 PM
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n, vector<int> (n, INT_MAX));

        for(int i = 0; i < n; i++) {
            adj[i][i] = 0;
        }

        for(int k = 0; k < edges.size(); k++) {
            int i = edges[k][0];
            int j = edges[k][1];
            int wt = edges[k][2];

            adj[i][j] = wt;
            adj[j][i] = wt;
        }  

        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(adj[i][via] != INT_MAX && adj[via][j] != INT_MAX) {
                        adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
                    }
                }
            }
        }

        int ans = -1;
        int ansDist = INT_MAX;

        for(int i = 0; i < n; i++) {
            int curr = 0;
            for(int j = 0; j < n; j++) {
                if(adj[i][j] <= distanceThreshold) {
                    curr++;
                }
            }

            if(curr <= ansDist) {
                ansDist = curr;
                ans = i;
            }
        }

        return ans;
    }
};