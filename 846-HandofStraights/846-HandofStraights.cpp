// Last updated: 7/25/2026, 12:51:15 AM
1class Solution {
2public:
3    bool isNStraightHand(vector<int>& hand, int groupSize) {
4        int n = hand.size();
5
6        if(n % groupSize != 0) {
7            return false;
8        }
9
10        map<int, int> m;
11
12        for(int i = 0; i < n; i++) {
13            m[hand[i]]++;
14        }
15
16        for(auto &entry : m) {
17            int card = entry.first;
18            int freq = entry.second;
19
20            if(freq == 0) continue;
21
22            for(int i = 1; i <= groupSize-1; i++) {
23                if(m[card+i] < freq) {
24                    return false;
25                } else {
26                    m[card+i] -= freq;
27                }
28            }
29        }
30
31        return true;
32    }
33};