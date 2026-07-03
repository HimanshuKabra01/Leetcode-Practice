// Last updated: 7/3/2026, 7:59:14 PM
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
62    int largestIsland(vector<vector<int>>& grid) {
63        int n = grid.size();
64
65        vector<vector<bool>> vis(n, vector<bool> (n, false));
66        DisjointSet ds((n*n)-1);
67        int ans = 0;
68
69        for(int i = 0; i < n; i++) {
70            for(int j = 0; j < n; j++) {
71                if(grid[i][j] == 1 && !vis[i][j]) {
72                    queue<pair<int, int>> q;
73                    q.push({i, j});
74                    vis[i][j] = true;
75
76                    while(!q.empty()) {
77                        int r = q.front().first;
78                        int c = q.front().second;
79
80                        q.pop();
81
82                        if(r-1 >= 0 && !vis[r-1][c] && grid[r-1][c] == 1) {
83                            if(ds.findUPar(r*n + c) != ds.findUPar((r-1)*n+c)) {
84                                ds.unionBySize(r*n + c, (r-1)*n+c);
85                                vis[r-1][c] = true;
86                                q.push({r-1, c});
87                            }
88                        }
89
90                        if(r+1 < n && !vis[r+1][c] && grid[r+1][c] == 1) {
91                            if(ds.findUPar(r*n + c) != ds.findUPar((r+1)*n+c)) {
92                                ds.unionBySize(r*n + c, (r+1)*n+c);
93                                vis[r+1][c] = true;
94                                q.push({r+1, c});
95                            }
96                        }
97
98                        if(c-1 >= 0 && !vis[r][c-1] && grid[r][c-1] == 1) {
99                            if(ds.findUPar(r*n + c) != ds.findUPar(r*n+(c-1))) {
100                                ds.unionBySize(r*n + c, r*n+(c-1));
101                                vis[r][c-1] = true;
102                                q.push({r, c-1});
103                            }
104                        }
105
106                        if(c+1 < n && !vis[r][c+1] && grid[r][c+1] == 1) {
107                            if(ds.findUPar(r*n + c) != ds.findUPar(r*n+(c+1))) {
108                                ds.unionBySize(r*n + c, r*n+(c+1));
109                                vis[r][c+1] = true;
110                                q.push({r, c+1});
111                            }
112                        }
113
114                        ans = max(ans, ds.getSize(r*n + c));
115                    }
116                }
117            }
118        }
119
120        for(int i = 0; i < n; i++) {
121            for(int j = 0; j < n; j++) {
122                if(grid[i][j] == 0) {
123                    unordered_set<int> st;
124                    int temp = 0;
125                    
126                    if(i-1 >= 0 && grid[i-1][j] == 1 && st.find(ds.findUPar((i-1)*n + j)) == st.end()) {
127                        temp += ds.getSize((i-1)*n + j);
128                        st.insert(ds.findUPar((i-1)*n + j));
129                    }
130
131                    if(j-1 >= 0 && grid[i][j-1] == 1 && st.find(ds.findUPar(i*n + (j-1))) == st.end()) {
132                        temp += ds.getSize(i*n + (j-1));
133                        st.insert(ds.findUPar(i*n + (j-1)));
134                    }
135
136                    if(i+1 < n && grid[i+1][j] == 1 && st.find(ds.findUPar((i+1)*n + j)) == st.end()) {
137                        temp += ds.getSize((i+1)*n + j);
138                        st.insert(ds.findUPar((i+1)*n + j));
139                    }
140
141                    if(j+1 < n && grid[i][j+1] == 1 && st.find(ds.findUPar(i*n + (j+1))) == st.end()) {
142                        temp += ds.getSize(i*n + (j+1));
143                        st.insert(ds.findUPar(i*n + (j+1)));
144                    }
145
146                    temp++;
147
148                    ans = max(ans,temp);
149                }
150            }
151        }
152
153        return ans;
154    }
155};