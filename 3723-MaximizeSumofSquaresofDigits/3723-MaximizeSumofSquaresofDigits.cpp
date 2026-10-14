// Last updated: 10/14/2026, 8:23:32 PM
1class Solution {
2public:
3    string maxSumOfSquares(int num, int sum) {
4        string ans = "";
5        int i = 0;
6
7        while(i < num) {
8            if(sum <= 9) {
9                ans += to_string(sum);
10                sum = 0;
11            } else {
12                ans += to_string(9);
13                sum = sum - 9;
14            }
15            i++;
16        }
17
18        if(sum != 0) {
19            return "";
20        } else {
21            return ans;
22        }
23    }
24};