// Last updated: 10/7/2025, 6:46:13 PM
class Solution {
public:
    void getCombin(vector<vector<int>>& ans, vector<int>& comb, int st, int n, int k) {
        if(comb.size() == k) {
            ans.push_back({comb});
            return;
        }

        for(int i = st; i <= n; i++) {
            comb.push_back(i);
            getCombin(ans, comb, i+1, n, k);
            comb.pop_back();
        }  
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;

        getCombin(ans, comb, 1, n, k);

        return ans;
    }
};