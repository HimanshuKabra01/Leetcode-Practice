// Last updated: 7/16/2025, 11:59:09 PM
class Solution {
public:
    bool isAlphaNumeric(char s) {
        if(tolower(s) >= 'a' && tolower(s) < 'z') return true;
        if(s >= '0' && s <='9') return true;

        return false;
    }

    bool isPalindrome(string s) {

        int n = s.length();

        int st = 0;
        int end = n-1;

        while(st < end) {
            if(!isAlphaNumeric(s[st])) {
                st++;
                continue;
            }
            if(!isAlphaNumeric(s[end])) {
                end--;
                continue;
            }

            if(tolower(s[st]) != tolower(s[end])) return false;

            st++;
            end--;
        } 

        return true; 
    }
};