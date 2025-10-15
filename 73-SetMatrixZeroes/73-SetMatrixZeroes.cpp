// Last updated: 10/16/2025, 12:43:19 AM
class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
      int m = mat.size();
      int n = mat[0].size();
      unordered_set<int> rows;
      unordered_set<int> cols;

      for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(mat[i][j] == 0) {
                rows.insert(i);
                cols.insert(j);
            }
        }
      }

      for(int i = 0; i < m; i++) {
        for(int col : cols) {
            mat[i][col] = 0;
        }
      }

      for(int j = 0; j < n; j++) {
        for(int row : rows) {
            mat[row][j] = 0;
        }
      } 
    }
};