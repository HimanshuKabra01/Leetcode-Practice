// Last updated: 8/9/2026, 12:31:15 PM
class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans;
        while(true) {
            int prod = 1;
            int num = n;
            while(num > 0) {
                int dig = num % 10;

                prod *= dig;

                num /= 10;
            }

            if(prod % t == 0) {
                ans = n;
                break;
            }

            n++;
        }

        return ans;
    }
};