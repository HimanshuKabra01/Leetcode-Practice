// Last updated: 8/9/2026, 12:40:46 PM
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans(n);

        if(n == 1) {
            return {{1}};
        } else {
            int i = 0;
            ans[i].push_back(1);
            i++;

            while(i < n){
                ans[i].push_back(1);

                for(int j = 0; j < i-1; j++) {
                    int curr = ans[i-1][j] + ans[i-1][j+1];

                    ans[i].push_back(curr);
                }

                ans[i].push_back(1);

                i++;
            }
        }

        return ans;
    }
};