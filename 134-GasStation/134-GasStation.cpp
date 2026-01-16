// Last updated: 1/16/2026, 3:27:59 PM
1class Solution {
2public:
3    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
4        int n = gas.size();
5        int totalGas = 0;
6        int totalCost = 0;
7
8        for(int i = 0; i < n; i++) {
9            totalGas += gas[i];
10            totalCost += cost[i];
11        }
12
13        if(totalCost > totalGas) return -1;
14
15        int st = 0;
16        int currGas = 0;
17
18        for(int i = 0; i < n; i++) {
19            currGas += gas[i] - cost[i];
20
21            if(currGas < 0) {
22                st = i + 1;
23                currGas = 0;
24            }
25        }
26
27        return st;
28    }
29};