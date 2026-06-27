// Last updated: 6/28/2026, 1:59:58 AM
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
57    int makeConnected(int n, vector<vector<int>>& connections) {
58        if(connections.size() < n-1) {
59            return -1;
60        }
61
62        DisjointSet ds(n);
63
64        for(int i = 0; i < connections.size(); i++) {
65            ds.unionBySize(connections[i][0], connections[i][1]);
66        }
67
68        int dis = 0;
69        for(int i = 0; i < n; i++) {
70            if(ds.findUPar(i) == i) {
71                dis++;
72            }
73        }
74
75        if(dis == 1) {
76            return 0;
77        }
78
79        return dis-1;
80    }
81};