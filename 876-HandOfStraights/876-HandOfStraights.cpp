// Last updated: 8/9/2026, 12:35:22 PM
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize != 0) {
            return false;
        }

        map<int, int> m;

        for(int i = 0; i < n; i++) {
            m[hand[i]]++;
        }

        for(auto &entry : m) {
            int card = entry.first;
            int freq = entry.second;

            if(freq == 0) continue;

            for(int i = 1; i <= groupSize-1; i++) {
                if(m[card+i] < freq) {
                    return false;
                } else {
                    m[card+i] -= freq;
                }
            }
        }

        return true;
    }
};