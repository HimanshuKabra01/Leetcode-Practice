// Last updated: 7/26/2025, 6:01:14 PM
class Solution {
public:
    bool searchInRow(vector<vector<int>>&matrix, int target, int row) {
        int n = matrix[0].size();
        int st = 0;
        int end = n-1;

        while(st <= end) {
            int mid = st + (end-st)/2;

            if(matrix[row][mid] == target) {
                return true;
            } else if(target >= matrix[row][mid]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int stR = 0;
        int endR = m - 1;

        while(stR <= endR) {
            int midR = stR + (endR - stR)/2;

            if(matrix[midR][0] <= target && target <= matrix[midR][n-1]) {
                return searchInRow(matrix, target, midR);
            }else if(target >= matrix[midR][n-1]){
                stR = midR + 1;
            } else {
                endR = midR - 1;
            }
        }

        return false;
    }
};