// Last updated: 8/26/2025, 12:27:36 PM
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int area;
        int maxDiagonal = INT_MIN;

        for(int i = 0; i < n; i++) {
            int length = dimensions[i][0];
            int breadth = dimensions[i][1];

            int diagonalSq = (length * length) + (breadth*breadth);

            if (diagonalSq > maxDiagonal || (diagonalSq == maxDiagonal && length * breadth > area)) {
                area = length * breadth;
                maxDiagonal = diagonalSq;
            }

        }

        return area;
    }
};