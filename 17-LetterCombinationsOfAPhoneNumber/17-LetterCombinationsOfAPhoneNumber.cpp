// Last updated: 8/9/2026, 12:43:05 PM
class Solution {
public:
    void rec(string &digits, int i, vector<string> &ans, string curr, unordered_map<char, string> &m) {
        if(i > digits.size()) {
            return;
        }

        if(i == digits.size()) {
            ans.push_back(curr);
            return;
        }

        for(int j = 0; j < m[digits[i]].size(); j++) {
            rec(digits, i+1, ans, curr+m[digits[i]][j], m);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        unordered_map<char, string> mp;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        rec(digits, 0, ans, "", mp);

        return ans;
    }
};