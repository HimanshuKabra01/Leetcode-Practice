// Last updated: 6/25/2025, 11:46:15 PM
class Solution {
public:
    double myPow(double x, int n) {
        long binForm = n;
        if(binForm < 0) {
            x = 1/x;
            binForm = -binForm;
        }
        double ans = 1;

        while (binForm > 0) {
            if(binForm % 2 == 1) {
                ans *= x;
            }
            x *= x;
            binForm /= 2;
        }
        return ans;
    }
};