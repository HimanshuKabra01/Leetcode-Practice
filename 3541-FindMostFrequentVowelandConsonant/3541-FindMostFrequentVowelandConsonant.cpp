// Last updated: 9/13/2025, 5:51:10 PM
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