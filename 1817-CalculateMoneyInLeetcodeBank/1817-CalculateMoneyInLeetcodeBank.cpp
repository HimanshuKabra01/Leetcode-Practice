// Last updated: 8/9/2026, 12:32:59 PM
class Solution {
public:
    int totalMoney(int n) {
        int i = 1;
        int st = 0;
        int mon = st;
        int ans = 0;

        while(i <= n) {
            if(i % 7 == 1) {
                st++;
                mon = st;
            }

            ans += mon;

            mon++;
            i++;
        }

        return ans;
    }
};