// Last updated: 8/28/2026, 1:30:14 AM
1class Solution {
2public:
3    string multiply(string num1, string num2) {
4        int m = num1.length();
5        int n = num2.length();
6
7        if (num1 == "0" || num2 == "0") {
8            return "0";
9        }
10
11        vector<int> res(m+n, 0);
12
13        for(int i = m-1; i >= 0; i--) {
14            for(int j = n-1; j >= 0; j--) {
15                int mul = (num1[i]-'0')*(num2[j]-'0');
16
17                int p1 = i+j;
18                int p2 = i+j+1;
19
20                int sum = mul+res[p2];
21
22                res[p2] = sum % 10;
23                res[p1] += sum / 10;
24            }
25        }
26
27        string ans = "";
28        for(int dig: res) {
29            if (!(ans.empty() && dig == 0)) {
30                ans.push_back(dig + '0');
31            }
32        }
33
34        return ans;
35    }
36};