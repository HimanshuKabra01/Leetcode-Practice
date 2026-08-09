// Last updated: 8/9/2026, 12:35:25 PM
class DisjointSet {
  vector<int> rank, parent, size;
public:
  DisjointSet(int n) {
    rank.resize(n+1, 0);
    parent.resize(n+1);
    size.resize(n+1);
    for(int i = 0; i <= n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  // PATH COMPRESSION - CHANGES COMPLEXITY FROM LOG N TO CONSTANT
  int findUPar(int u) {
    if(u == parent[u]) {
      return u;
    }

    return parent[u] = findUPar(parent[u]);
  }

  void unionByRank(int u, int v) {
    int ulU = findUPar(u);
    int ulV = findUPar(v);

    if(ulU == ulV) return;

    if(rank[ulU] < rank[ulV]) {
      parent[ulU] = ulV;
    } else if(rank[ulV] < rank[ulU]) {
      parent[ulV] = ulU;
    } else {
      parent[ulV] = ulU;
      rank[ulU]++;
    }
  }

  void unionBySize(int u, int v) {
    int ulU = findUPar(u);
    int ulV = findUPar(v);

    if(ulU == ulV) return;

    if(size[ulU] < size[ulV]) {
      parent[ulU] = ulV;
      size[ulV] += size[ulU];
    } else {
      parent[ulV] = ulU;
      size[ulU] += size[ulV];
    }
  }

  int getSize(int node) {
    int ulParent = findUPar(node);
    return size[ulParent];
}
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<bool>> vis(n, vector<bool> (n, false));
        DisjointSet ds((n*n)-1);
        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = true;

                    while(!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;

                        q.pop();

                        if(r-1 >= 0 && !vis[r-1][c] && grid[r-1][c] == 1) {
                            if(ds.findUPar(r*n + c) != ds.findUPar((r-1)*n+c)) {
                                ds.unionBySize(r*n + c, (r-1)*n+c);
                                vis[r-1][c] = true;
                                q.push({r-1, c});
                            }
                        }

                        if(r+1 < n && !vis[r+1][c] && grid[r+1][c] == 1) {
                            if(ds.findUPar(r*n + c) != ds.findUPar((r+1)*n+c)) {
                                ds.unionBySize(r*n + c, (r+1)*n+c);
                                vis[r+1][c] = true;
                                q.push({r+1, c});
                            }
                        }

                        if(c-1 >= 0 && !vis[r][c-1] && grid[r][c-1] == 1) {
                            if(ds.findUPar(r*n + c) != ds.findUPar(r*n+(c-1))) {
                                ds.unionBySize(r*n + c, r*n+(c-1));
                                vis[r][c-1] = true;
                                q.push({r, c-1});
                            }
                        }

                        if(c+1 < n && !vis[r][c+1] && grid[r][c+1] == 1) {
                            if(ds.findUPar(r*n + c) != ds.findUPar(r*n+(c+1))) {
                                ds.unionBySize(r*n + c, r*n+(c+1));
                                vis[r][c+1] = true;
                                q.push({r, c+1});
                            }
                        }

                        ans = max(ans, ds.getSize(r*n + c));
                    }
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    unordered_set<int> st;
                    int temp = 0;
                    
                    if(i-1 >= 0 && grid[i-1][j] == 1 && st.find(ds.findUPar((i-1)*n + j)) == st.end()) {
                        temp += ds.getSize((i-1)*n + j);
                        st.insert(ds.findUPar((i-1)*n + j));
                    }

                    if(j-1 >= 0 && grid[i][j-1] == 1 && st.find(ds.findUPar(i*n + (j-1))) == st.end()) {
                        temp += ds.getSize(i*n + (j-1));
                        st.insert(ds.findUPar(i*n + (j-1)));
                    }

                    if(i+1 < n && grid[i+1][j] == 1 && st.find(ds.findUPar((i+1)*n + j)) == st.end()) {
                        temp += ds.getSize((i+1)*n + j);
                        st.insert(ds.findUPar((i+1)*n + j));
                    }

                    if(j+1 < n && grid[i][j+1] == 1 && st.find(ds.findUPar(i*n + (j+1))) == st.end()) {
                        temp += ds.getSize(i*n + (j+1));
                        st.insert(ds.findUPar(i*n + (j+1)));
                    }

                    temp++;

                    ans = max(ans,temp);
                }
            }
        }

        return ans;
    }
};