// Last updated: 8/9/2026, 12:42:51 PM
class Solution {
public:
    void rec(int n, int i, int j, vector<string> &ans, string &s) {
        if(i+j == 2*n && i == j) {
            ans.push_back(s);
            return;
        }

        if(i < n) {
            s = s + "(";
            rec(n, i+1, j, ans, s);
            s.pop_back();
        }

        if(j < i) {
            s = s + ")";
            rec(n, i, j+1, ans, s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        string s = "";
        rec(n, 0, 0, ans, s);

        return ans;
    }
};