// Last updated: 8/13/2025, 1:22:49 AM
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    //    int n = grid.size(); 
    //    vector<int> freq(n*n + 1, 0);
    //    vector<int> ans;

    //    for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         freq[grid[i][j]-1]++;
    //     }
    //    }

    //    for(int i = 0; i < n*n; i++){
    //     if(freq[i] == 2) {
    //         ans.push_back(i+1);
    //     }
    //    }

    //    for(int i = 0; i < n*n; i++){
    //     if(freq[i] == 0) {
    //         ans.push_back(i+1);
    //     }
    //    } 

    //    return ans;

    unordered_set<int> s;
    vector<int> ans;
    int n = grid.size();
    int a, b;
    int expSum = 0, actualSum = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            actualSum += grid[i][j];

            if(s.find(grid[i][j]) != s.end()) {
                a = grid[i][j];
                ans.push_back(a);
            } 
            
            s.insert(grid[i][j]);
        }
    }

    expSum = (n*n) * (n*n + 1)/2;
    b = expSum + a - actualSum;
    ans.push_back(b);
    
    return ans;
    }
};