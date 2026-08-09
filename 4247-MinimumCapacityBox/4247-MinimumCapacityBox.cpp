// Last updated: 8/9/2026, 12:28:42 PM
class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = capacity.size();
        vector<int> sorted = capacity;

        sort(sorted.begin(), sorted.end());

        int elem = -1;
        for(int i = 0; i < n; i++) {
            if(sorted[i] >= itemSize) {
                elem = sorted[i];
                break;
            }
        }

        int ans = -1;

        for(int i = 0; i < n; i++) {
            if(elem == capacity[i]) {
                ans = i;
                break;
            }
        }

        return ans;
    }
};