// Last updated: 8/9/2026, 12:35:13 PM
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int end = piles[0];

        for(int i = 1; i < n; i++) {
            if(piles[i] > end) {
                end = piles[i];
            }
        }

        int st = 1;

        int ans = 0;
        while(st <= end) {
            double mid = st + (end-st)/2;

            long long time = 0;

            for(int i = 0; i < piles.size(); i++) {
                time += ceil(piles[i]/mid);
            }

            if(time <= h) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return ans;
    }
};