// Last updated: 8/9/2026, 12:31:38 PM
class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        
        vector<int> freq(26, 0);

        int dis = 0;

        for(int i = 0; i < n; i++) {
            if(freq[word[i] - 'a'] == 0) {
               dis++;     
            }
            freq[word[i] - 'a']++;
        } 

        sort(freq.begin(), freq.end());
        reverse(freq.begin(), freq.end());

        int ans = 0;

        if(dis <= 8) {
            for(int i = 0; i < 8; i++) {
                ans += freq[i];
            } 
        } else if(dis > 8 && dis <= 16) {
            for(int i = 0; i < 8; i++) {
                ans += freq[i];
            }

            for(int i = 8; i < 16; i++) {
                ans += freq[i]*2;
            } 
        } else if (dis > 16 && dis <= 24) {
            for(int i = 0; i < 8; i++) {
                ans += freq[i];
            }

            for(int i = 8; i < 16; i++) {
                ans += freq[i]*2;
            }

            for(int i = 16; i < 24; i++) {
                ans += freq[i]*3;
            }
        } else {
            for(int i = 0; i < 8; i++) {
                ans += freq[i];
            }

            for(int i = 8; i < 16; i++) {
                ans += freq[i]*2;
            }

            for(int i = 16; i < 24; i++) {
                ans += freq[i]*3;
            }

            ans += 4*freq[24];
            ans += 4*freq[25];
        }

        return ans;
    }
};