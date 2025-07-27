// Last updated: 7/27/2025, 3:34:43 PM
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0;
        int col = n - 1;

        while(col >= 0 && row < m) {
            int mid = matrix[row][col];

            if(target == mid) {
                return true;
            } else if(target > mid) {
                row++;
            } else {
                col--;
            }
        }

        return false;
    }
};