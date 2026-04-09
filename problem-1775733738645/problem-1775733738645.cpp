// Last updated: 4/9/2026, 4:52:18 PM
1class Solution {
2public:
3    void rec(int n, int i, int j, vector<string> &ans, string &s) {
4        if(i+j == 2*n && i == j) {
5            ans.push_back(s);
6            return;
7        }
8
9        if(i < n) {
10            s = s + "(";
11            rec(n, i+1, j, ans, s);
12            s.pop_back();
13        }
14
15        if(j < i) {
16            s = s + ")";
17            rec(n, i, j+1, ans, s);
18            s.pop_back();
19        }
20    }
21    vector<string> generateParenthesis(int n) {
22        vector<string> ans;
23
24        string s = "";
25        rec(n, 0, 0, ans, s);
26
27        return ans;
28    }
29};