// Last updated: 8/9/2026, 12:34:57 PM
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int ans = 0;

        DisjointSet ds(20001);

        unordered_set<int> par;
        unordered_set<int> ulP;
        for(int i = 0; i < n; i++) {
            int r = stones[i][0];
            int c = stones[i][1];

            ds.unionBySize(r, 10001+c);
            par.insert(r);
            par.insert(10001+c);
        }

        for(int x : par) {
            int p = ds.findUPar(x);

            ulP.insert(p);
        }

        return n - ulP.size();
    }
};