// Last updated: 8/9/2026, 12:35:02 PM
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int ans = 0;

        for(int i = 0; i < strs[0].size(); i++) {
            for(int j = 0; j < n-1; j++) {
                if(strs[j][i] > strs[j+1][i]) {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};