// Last updated: 8/9/2026, 12:33:46 PM
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        while(k != 0) {
            vector<int> last;
            for(int i = 0; i < m; i++) {
                last.push_back(grid[i][n-1]);
            }

            for(int j = n-2; j >= 0; j--) {
                for(int i = 0; i < m; i++) {
                    grid[i][j+1] = grid[i][j];
                } 
            }

            grid[0][0] = last[last.size()-1];

            for(int i = 1; i < last.size(); i++) {
                grid[i][0] = last[i-1];
            }

            k--;
        }

        return grid;        
    }
};