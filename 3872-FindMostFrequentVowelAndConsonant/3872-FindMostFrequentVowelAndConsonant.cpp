// Last updated: 8/9/2026, 12:30:48 PM
class Solution {
public:
    int maxFreqSum(string s) {
        int maxVow = 0;
        int maxConso = 0;
        int freq[26];

        for(char c : s) {
            int i = c - 'a';

            freq[i]++;

            if(c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u') {
                
                maxVow = max(maxVow, freq[i]);
            } else {
                maxConso = max(maxConso, freq[i]);
            }
        }


        return maxVow + maxConso;
    }
};