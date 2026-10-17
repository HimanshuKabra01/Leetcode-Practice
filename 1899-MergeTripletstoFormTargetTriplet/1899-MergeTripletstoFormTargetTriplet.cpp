// Last updated: 10/18/2026, 2:06:05 AM
1class Solution {
2public:
3    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
4        bool one = false;
5        bool two = false;
6        bool thr = false;
7
8        for(int i = 0; i < triplets.size(); i++) {
9            if(triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]) {
10                continue;
11            } 
12            
13            if(triplets[i][0] == target[0]) one = true;
14            if(triplets[i][1] == target[1]) two = true;
15            if(triplets[i][2] == target[2]) thr = true;
16        }
17
18        return one && two && thr;
19    }
20};