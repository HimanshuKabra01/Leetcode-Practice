// Last updated: 9/19/2026, 6:37:24 PM
1class Solution {
2public:
3    bool checkOverlap(int r, int x, int y, int x1, int y1, int x2, int y2) {
4        if (x + r < x1 || x-r > x2 || y-r > y2 || y+r < y1) {
5            return false;
6        }
7
8        if(x > x2 && y > y2) {
9            int d = sqrt((x-x2)*(x-x2) + (y-y2)*(y-y2));
10
11            if(d > r) {
12                return false;
13            }
14        } else if(x < x1 && y < y1) {
15            int d = sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
16
17            if(d > r) {
18                return false;
19            }
20        } else if(x < x1 && y > y2) {
21            int d = sqrt((x-x1)*(x-x1) + (y-y2)*(y-y2));
22
23            if(d > r) {
24                return false;
25            }
26        } else if(x > x2 && y < y1) {
27            int d = sqrt((x-x2)*(x-x2) + (y-y1)*(y-y1));
28
29            if(d > r) {
30                return false;
31            }
32        }
33
34        return true;
35    }
36};