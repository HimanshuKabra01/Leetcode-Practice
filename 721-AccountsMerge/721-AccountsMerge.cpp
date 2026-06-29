// Last updated: 6/29/2026, 7:21:52 PM
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
57    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
58        int n = accounts.size();
59
60        unordered_map<string, int> mp;
61        DisjointSet ds(n);
62
63        for(int i = 0; i < n; i++) {
64            for(int j = 1; j < accounts[i].size(); j++) {
65                string mail = accounts[i][j];
66
67                if(mp.find(mail) == mp.end()) {
68                    mp[mail] = i;
69                } else {
70                    ds.unionBySize(i, mp[mail]);
71                }
72            }
73        }
74
75        vector<vector<string>> ans;
76
77        unordered_map<int, vector<string>> m;
78
79        for(auto &entry : mp) {
80            string mail = entry.first;
81            int i = entry.second;
82
83            int par = ds.findUPar(i);
84
85            m[par].push_back(mail);
86        }
87
88        for(auto &entry : m) {
89            int id = entry.first;
90            vector<string> mails = entry.second;
91
92            sort(mails.begin(), mails.end());
93
94            vector<string> pus;
95            pus.push_back(accounts[id][0]);
96
97            for(int i = 0; i < mails.size(); i++) {
98                pus.push_back(mails[i]);
99            }
100
101            ans.push_back(pus);
102        }
103
104        return ans;
105    }
106};