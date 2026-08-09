// Last updated: 8/9/2026, 12:29:23 PM
class Solution {
public:
    int vowelConsonantScore(string s) {
        int n = s.size();
        int v = 0;
        int c = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a' || s[i] == 'i' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u') {
                v++;
            } else if(s[i] != ' ' && (s[i] != '1' && s[i] != '2' && s[i] != '3' && s[i] != '4' && s[i] != '5' && s[i] != '6' && s[i] != '7' && s[i] != '8' && s[i] != '9' && s[i] != '0')) {
                c++;
            }
        }

        if(c == 0) {
            return 0;
        }

        int ans = v / c;

        return ans;
    }
};