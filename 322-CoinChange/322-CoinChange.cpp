// Last updated: 5/1/2026, 1:02:28 PM
1class Solution {
2public:
3    bool bestSum(vector<int> &coins, int t, int &ans, unordered_map<int, int> &m, unordered_set<int> &im) {
4        if(im.find(t) != im.end()) return false;
5        if(m.count(t)) {
6            ans = m[t];
7            return true;
8        }
9        if(t == 0) return true;
10        if(t < 0) return false;
11
12        bool possible = false;
13        int shortest = INT_MAX;
14
15        for(int elem : coins) {
16            int subAns = 0;
17            if(bestSum(coins, t-elem, subAns, m, im)) {
18                possible = true;
19                subAns++;
20
21                if(subAns < shortest) {
22                    shortest = subAns;
23                }
24            }
25        }
26
27        if(possible) {
28            ans = shortest;
29            m[t] = shortest;
30        } else {
31            im.insert(t);
32        }
33
34        return possible;
35    }
36    int coinChange(vector<int>& coins, int amount) {
37        int ans = 0;
38        unordered_map<int, int> m;
39        unordered_set<int> im;
40
41        bool possible = bestSum(coins, amount, ans, m, im);
42
43        if(!possible) return -1;
44        else return ans;
45    }
46};