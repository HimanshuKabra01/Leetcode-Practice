// Last updated: 8/9/2026, 12:32:42 PM
class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
       for(int i = 1; i <= n; i++) {
        int a = i;
        for(int j = 1; j <= n; j++) {
            int b = j;

            int c = sqrt((a*a) + (b*b) + 1);

            if(c <= n && (c*c) == (a*a) + (b*b)) {
                ans++;
            }
        }
       }

       return ans;
    }
};