// Last updated: 10/25/2025, 9:02:31 PM
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        int i = 0;

        while(i < num) {
            if(sum <= 9) {
                ans += to_string(sum);
                sum = 0;
            } else {
                ans += to_string(9);
                sum = sum - 9;
            }
            i++;
        }

        if(sum != 0) {
            return "";
        } else {
            return ans;
        }
    }
};