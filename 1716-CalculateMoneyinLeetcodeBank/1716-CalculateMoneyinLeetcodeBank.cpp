// Last updated: 10/25/2025, 10:23:09 AM
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