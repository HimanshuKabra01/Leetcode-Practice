// Last updated: 7/23/2025, 3:28:22 PM
class Solution {
public:
    int reverse(int x) {
        int revNum = 0;

        while(x != 0) {
            int digit = x % 10;

            if(revNum > INT_MAX/10 || revNum < INT_MIN/10) {
                return 0;
            }

            revNum = (revNum * 10) + digit;

            x /= 10;
        }

        return revNum;
    };

    bool isPalindrome(int x) {
        // string str = to_string(x);

        // string str2 = str;

        // reverse(str2.begin(), str2.end());

        // if(str2 == str) {
        //     return true;
        // }

        // return false;

        if(x < 0) {
            return false;
        }

        int revNum = reverse(x);

        if(revNum == x) {
            return true;
        }

        return false;
     }
};