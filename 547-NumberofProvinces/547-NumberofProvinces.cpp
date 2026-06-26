// Last updated: 6/26/2026, 11:56:34 PM
1class DisjointSet {
2  vector<int> rank, parent, size;
3public:
4  DisjointSet(int n) {
5    rank.resize(n+1, 0);
6    parent.resize(n+1);
7    size.resize(n+1);
8    for(int i = 0; i <= n; i++) {
9      parent[i] = i;
10      size[i] = 1;
11    }
12  }
13
14  // PATH COMPRESSION - CHANGES COMPLEXITY FROM LOG N TO CONSTANT
15  int findUPar(int u) {
16    if(u == parent[u]) {
17      return u;
18    }
19
20    return parent[u] = findUPar(parent[u]);
21  }
22
23  void unionByRank(int u, int v) {
24    int ulU = findUPar(u);
25    int ulV = findUPar(v);
26
27    if(ulU == ulV) return;
28
29    if(rank[ulU] < rank[ulV]) {
30      parent[ulU] = ulV;
31    } else if(rank[ulV] < rank[ulU]) {
32      parent[ulV] = ulU;
33    } else {
34      parent[ulV] = ulU;
35      rank[ulU]++;
36    }
37  }
38
39  void unionBySize(int u, int v) {
40    int ulU = findUPar(u);
41    int ulV = findUPar(v);
42
43    if(ulU == ulV) return;
44
45    if(size[ulU] < size[ulV]) {
46      parent[ulU] = ulV;
47      size[ulU] += size[ulV];
48    } else {
49      parent[ulV] = ulU;
50      size[ulV] += size[ulU];
51    }
52  }
53};
54
55class Solution {
56public:
57    int findCircleNum(vector<vector<int>>& isConnected) {\
58        int n = isConnected.size();
59        DisjointSet ds(n);
60
61        for(int i = 0; i < n; i++) {
62            for(int j = 0; j < n; j++) {
63                if(isConnected[i][j] == 1) {
64                    ds.unionBySize(i, j);
65                }
66            }
67        }
68
69        int ans = 0;
70
71        for(int i = 0; i < n; i++) {
72            if(ds.findUPar(i) == i) {
73                ans++;
74            }
75        }
76
77        return ans;
78    }
79};