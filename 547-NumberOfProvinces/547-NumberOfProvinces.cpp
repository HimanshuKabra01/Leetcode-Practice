// Last updated: 8/9/2026, 12:36:53 PM
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
      size[ulU] += size[ulV];
    } else {
      parent[ulV] = ulU;
      size[ulV] += size[ulU];
    }
  }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {\
        int n = isConnected.size();
        DisjointSet ds(n);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1) {
                    ds.unionBySize(i, j);
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(ds.findUPar(i) == i) {
                ans++;
            }
        }

        return ans;
    }
};