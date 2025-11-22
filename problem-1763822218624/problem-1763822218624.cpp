// Last updated: 11/22/2025, 8:06:58 PM
class Solution {
public:
    int minimumFlips(int n) {
       string binform = "";

        while(n > 0) {
            int dig = n % 2;

            binform += to_string(dig);
            n /= 2;
        }
        int size = binform.size();
        int ans = 0;
        string reversed = binform;
        reverse(reversed.begin(), reversed.end());

        for(int i = 0; i < size; i++) {
            if(binform[i] != reversed[i]) {
                ans++;
            }
        }

        return ans;
    }
};