// Last updated: 3/29/2026, 1:46:00 AM
1class Solution {
2public:
3    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
4       int m = image.size();
5       int n = image[0].size();
6
7        if(image[sr][sc] == color) {
8            return image;
9        }
10       queue<pair<int, int>> q;
11       q.push({sr, sc});
12       
13       int val = image[sr][sc];
14       image[sr][sc] = color;
15
16       while(!q.empty()) {
17        int i = q.front().first;
18        int j = q.front().second;
19
20        q.pop();
21
22        if(i-1 >=0 && image[i-1][j] == val) {
23            q.push({i-1, j});
24            image[i-1][j] = color;
25        }
26
27        if(j+1 < n && image[i][j+1] == val) {
28            q.push({i, j+1});
29            image[i][j+1] = color;
30        }
31
32        if(i+1 < m && image[i+1][j] == val) {
33            q.push({i+1, j});
34            image[i+1][j] = color;
35        }
36
37        if(j-1 >=0 && image[i][j-1] == val) {
38            q.push({i, j-1});
39            image[i][j-1] = color;
40        }
41       }
42
43       return image;
44    }
45};