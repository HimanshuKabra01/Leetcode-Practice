// Last updated: 10/23/2025, 11:43:13 AM
class Solution {
public:
    bool hasSameDigits(string s) {
       int n = s.size();
       
       while(n > 2) {
        string t = "";

        for(int i = 0; i < n - 1; i++) {
            int a = s[i] - '0';
            int b = s[i + 1] - '0';

            int dig = (a+b) % 10;

            t += to_string(dig);
        }

        s = t;
        n = s.size();
       }

       if(s[0] == s[1]) {
        return true;
       }

       return false;
    }
};