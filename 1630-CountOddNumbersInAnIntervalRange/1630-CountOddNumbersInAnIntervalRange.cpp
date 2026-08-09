// Last updated: 8/9/2026, 12:33:14 PM
class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;

        for(int i = low; i <= high; i++) {
            if(i % 2 != 0) {
                count++;
            }
        }

        return count;
    }
};