// Last updated: 8/2/2025, 4:39:43 PM
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int srow = 0, scol = 0;
        int erow = m - 1;
        int ecol = n - 1;

        vector<int> ans;

        while(srow <= erow && scol <= ecol ) {
            for(int i = scol; i <= ecol; i++) {
                ans.push_back(mat[srow][i]);
            }

            for(int j = srow + 1; j <= erow; j++) {
                ans.push_back(mat[j][ecol]);
            }

            for(int i = ecol - 1; i >= scol; i--) {
                if(srow == erow) {
                    break;
                }

                ans.push_back(mat[erow][i]);
            }

            for(int j = erow - 1; j >= srow + 1; j--) {
                if(ecol == scol) {
                    break;
                }
                
                ans.push_back(mat[j][scol]);
            }

            srow++;
            scol++;
            erow--;
            ecol--;
        }

        return ans;
    }
};
