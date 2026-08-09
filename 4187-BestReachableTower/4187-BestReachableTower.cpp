// Last updated: 8/9/2026, 12:29:19 PM
class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int n = towers.size();
        vector<int> ans;
        vector<vector<int>> reachable;
        int quality = 0;

        for(int i = 0; i < n; i++) {
            int manhattan = abs(towers[i][0] - center[0]) + abs(towers[i][1] - center[1]);

            if(manhattan <= radius) {
                reachable.push_back(towers[i]);

                if(quality < towers[i][2]) {
                    quality = towers[i][2];
                }
            }
        }

        if(reachable.size() == 1) {
            return {reachable[0][0], reachable[0][1]};
        } else {
            sort(reachable.begin(), reachable.end());
            
            for(int i = 0; i < reachable.size(); i++) {
                if(reachable[i][2] == quality) {
                    return {reachable[i][0], reachable[i][1]};
                }
            }
        }

        return {-1, -1};
    }
};