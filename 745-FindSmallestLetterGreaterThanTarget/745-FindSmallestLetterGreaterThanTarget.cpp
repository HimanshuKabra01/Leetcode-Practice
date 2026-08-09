// Last updated: 8/9/2026, 12:36:10 PM
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();

        char ans = letters[0];

        int st = 0;
        int end = n - 1;

        while(st <= end) {
            int mid = st + (end-st)/2;

            if(letters[mid] <= target) {
                st = mid + 1;
            } else {
                end = mid - 1;
                ans = letters[mid];
            }
        }

        return ans;
    }
};