// Last updated: 10/9/2025, 10:48:28 AM
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int n = spells.size();
        int m = potions.size();

        sort(potions.begin(), potions.end());

        for(int i = 0; i < n; i++) {
            int st = 0;
            int end = m - 1;
            int firstValid = m;

            while(st <= end) {
                int mid = st + (end-st)/2;

                long long prod = (long)spells[i]*potions[mid];

                if(prod >= success) {
                    firstValid = mid;
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            }

            ans.push_back(m - firstValid);
        }
        return ans;
    }
};