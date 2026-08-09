// Last updated: 8/9/2026, 12:28:28 PM
class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char, int> mp;
        unordered_set<char> st;

        for(int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }

        int ans = 0;
        for (auto &it : mp) {
            char ch = it.first;
            char m;

            if (st.find(ch) != st.end()) continue;

            if (!isdigit(ch)) {
                m = 'z' - (ch - 'a');
            } else {
                m = '9' - (ch - '0');
            }

            st.insert(ch);
            st.insert(m);

            int freqM = 0;
            if(mp.count(m)) {
                freqM = mp[m];
            }

            ans += abs(mp[ch]-freqM);
        }

        return ans;
    }
};