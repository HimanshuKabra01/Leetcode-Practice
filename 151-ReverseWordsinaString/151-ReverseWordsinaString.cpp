// Last updated: 7/19/2025, 7:33:29 PM
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";

        reverse(s.begin(), s.end());

        for(int i = 0; i < n; i++) {
            string word = "";

            while(i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());

            if(word.length()) {
                ans += " "+ word;
            }
        }

        return ans.substr(1);
    }
};