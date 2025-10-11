// Last updated: 10/11/2025, 8:27:23 PM
class Solution {
public:
    bool scoreBalance(string s) {
        int n = s.size();
        int total = 0;

        for(char c : s) {
            total += c - 'a' + 1;
        }

        int leftSum = 0;
        for(int i = 0; i < n - 1;i++) {
            leftSum += s[i] - 'a' + 1;

            int rightSum = total - leftSum;

            if(rightSum == leftSum) {
                return true;
            }
        }

        return false;
    }
};