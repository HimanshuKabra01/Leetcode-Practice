// Last updated: 7/20/2025, 2:44:28 PM
class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);

        string str2 = str;

        reverse(str2.begin(), str2.end());

        if(str2 == str) {
            return true;
        }

        return false;
     }
};