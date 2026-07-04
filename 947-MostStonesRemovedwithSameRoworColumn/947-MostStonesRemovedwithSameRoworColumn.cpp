// Last updated: 7/4/2026, 5:55:33 PM
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
47      size[ulV] += size[ulU];
48    } else {
49      parent[ulV] = ulU;
50      size[ulU] += size[ulV];
51    }
52  }
53
54  int getSize(int node) {
55    int ulParent = findUPar(node);
56    return size[ulParent];
57}
58};
59
60class Solution {
61public:
62    int removeStones(vector<vector<int>>& stones) {
63        int n = stones.size();
64        int ans = 0;
65
66        DisjointSet ds(20001);
67
68        unordered_set<int> par;
69        unordered_set<int> ulP;
70        for(int i = 0; i < n; i++) {
71            int r = stones[i][0];
72            int c = stones[i][1];
73
74            ds.unionBySize(r, 10001+c);
75            par.insert(r);
76            par.insert(10001+c);
77        }
78
79        for(int x : par) {
80            int p = ds.findUPar(x);
81
82            ulP.insert(p);
83        }
84
85        return n - ulP.size();
86    }
87};