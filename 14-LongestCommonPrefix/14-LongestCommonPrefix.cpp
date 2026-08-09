// Last updated: 8/9/2026, 12:43:10 PM
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 1) {
            return strs[0];
        }
        string ans = strs[0];
        
        for(int i = 1; i < n; i++) {
            string s = strs[i];
            int sz1 = ans.size();
            int sz2 = s.size();

            if(sz2 < sz1) {
                ans.erase(sz2);
            }
            
            for(int j = 0; j < ans.size() && j < s.size(); j++) {
                if(ans[j] != s[j]) {
                    ans.erase(j);
                }
            }
        }

        return ans;
    }
};