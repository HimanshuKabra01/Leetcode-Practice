// Last updated: 10/27/2025, 11:20:44 AM
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        if(bank.empty()) return 0;
        vector<int> counts;
        int n = bank.size();
        int m = bank[0].size();

        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < m; j++) {
                if(bank[i][j] == '1') {
                    count++;
                }
            }
            if(count == 0) continue; 
            else counts.push_back(count);
        }

        int ans = 0;

        if(counts.size() == 0) {
            return 0;
        }

        for(int i = 0; i < counts.size() - 1; i++) {
            ans += counts[i] * counts[i+1];
        }

        return ans;
    }
};