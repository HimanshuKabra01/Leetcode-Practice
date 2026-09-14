// Last updated: 9/15/2026, 1:29:43 AM
1class Solution {
2public:
3    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
4        int x1 = rec1[0];
5        int y1 = rec1[1];
6        int x2 = rec1[2];
7        int y2 = rec1[3];
8        int X1 = rec2[0];
9        int Y1 = rec2[1];
10        int X2 = rec2[2];
11        int Y2 = rec2[3];
12
13        if((X2 <= x1) || (X1 >= x2) || (Y1 >= y2) || (y1 >= Y2)) {
14            return false;
15        }
16
17        return true;
18    }
19};