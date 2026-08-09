// Last updated: 8/9/2026, 12:32:08 PM
class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();
        string ans;
        string word;
        char s = num[0];
        int freq = 1;
        for(int i = 1; i < n; i++){
            
            if(s == num[i]) {
                freq++;
            } else {
                s = num[i];
                freq = 1;
            }

            if(freq == 3) {
                word = string(3, num[i]);
                ans = max(ans, word);
            }
        }

        return ans;    
    }
};