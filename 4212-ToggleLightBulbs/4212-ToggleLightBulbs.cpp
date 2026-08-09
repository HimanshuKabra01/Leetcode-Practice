// Last updated: 8/9/2026, 12:29:03 PM
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> ans;
        map<int, int> m;

        for(int i = 0; i < bulbs.size(); i++) {
            m[bulbs[i]]++;
        }

        for(auto &entry : m) {
            if(entry.second % 2 != 0) {
                ans.push_back(entry.first);
            }
        }

        return ans;
    }
};