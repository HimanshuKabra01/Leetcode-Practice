// Last updated: 4/19/2026, 1:55:29 AM
1class Solution {
2public:
3    void rec(string &digits, int i, vector<string> &ans, string curr, unordered_map<char, string> &m) {
4        if(i > digits.size()) {
5            return;
6        }
7
8        if(i == digits.size()) {
9            ans.push_back(curr);
10            return;
11        }
12
13        for(int j = 0; j < m[digits[i]].size(); j++) {
14            rec(digits, i+1, ans, curr+m[digits[i]][j], m);
15        }
16    }
17    vector<string> letterCombinations(string digits) {
18        vector<string> ans;
19
20        unordered_map<char, string> mp;
21
22        mp['2'] = "abc";
23        mp['3'] = "def";
24        mp['4'] = "ghi";
25        mp['5'] = "jkl";
26        mp['6'] = "mno";
27        mp['7'] = "pqrs";
28        mp['8'] = "tuv";
29        mp['9'] = "wxyz";
30
31        rec(digits, 0, ans, "", mp);
32
33        return ans;
34    }
35};