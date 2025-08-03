// Last updated: 8/3/2025, 1:49:51 PM
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
       int n = grid.size(); 
       vector<int> freq(n*n + 1, 0);
       vector<int> ans;

       for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            freq[grid[i][j]-1]++;
        }
       }

       for(int i = 0; i < n*n; i++){
        if(freq[i] == 2) {
            ans.push_back(i+1);
        }
       }

       for(int i = 0; i < n*n; i++){
        if(freq[i] == 0) {
            ans.push_back(i+1);
        }
       } 

       return ans;
    }
};