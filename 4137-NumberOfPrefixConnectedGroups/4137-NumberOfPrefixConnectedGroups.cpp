// Last updated: 8/9/2026, 12:29:34 PM
class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int n = words.size();
        int ans = 0;

        if(n == 1) {
            return 0;
        }

        sort(words.begin(), words.end());

        vector<string> focus;

        for(int i = 0; i < n; i++) {
            string s = words[i];

            if(s.size() < k) {
                continue;
            }

            s.resize(k); 

            focus.push_back(s);
        }

        int i = 0;
        while(i < focus.size()) {
            int j = i + 1;

            while(j < focus.size() && focus[j] == focus[i]) {
                j++;
            }

            if(j-i >= 2) {
                ans++;
            }

            i = j;  
        }

        return ans;
    }
};