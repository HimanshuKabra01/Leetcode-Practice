// Last updated: 8/9/2026, 12:29:05 PM
class Solution {
public:
    string reverseByType(string s) {
        int n = s.size();

        string letters = "";
        string character = "";
        string ans = "";

        for(int i = 0; i < n; i++) {
            if(isalnum(s[i])) {
                letters += s[i];
            } else {
                character += s[i];
            }
        }

        reverse(letters.begin(), letters.end());
        reverse(character.begin(), character.end());

        int m = letters.size();
        int o = character.size();

        int st = 0;
        int end = 0;

        for(int i = 0; i < n; i++) {
            if(isalnum(s[i])) {
                if(st > m) continue;
                else {
                    ans += letters[st];

                    st++;
                }
            } else {
                if(end > o) continue;
                else {
                    ans += character[end];

                    end++;
                }
            }
        }

        return ans;
    }
};