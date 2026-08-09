// Last updated: 8/9/2026, 12:33:35 PM
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) {
            return -1;
        }

        DisjointSet ds(n);

        for(int i = 0; i < connections.size(); i++) {
            ds.unionBySize(connections[i][0], connections[i][1]);
        }

        int dis = 0;
        for(int i = 0; i < n; i++) {
            if(ds.findUPar(i) == i) {
                dis++;
            }
        }

        if(dis == 1) {
            return 0;
        }

        return dis-1;
    }
};