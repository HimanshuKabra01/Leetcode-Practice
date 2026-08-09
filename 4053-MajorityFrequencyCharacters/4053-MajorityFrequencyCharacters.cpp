// Last updated: 8/9/2026, 12:30:12 PM
class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char, int> m;
        unordered_map<int, string> grps;

        for(int i = 0; i < s.size(); i++) {
          m[s[i]]++;  
        }

        for(auto &entry : m) {
            char character = entry.first;
            int count = entry.second;

            grps[count] += character;
        }

        int maxFreq = 0;
        int maxSize = 0;
        for(auto &it : grps) {
            int currFreq = it.first;
            int currSize = it.second.size();

            if(currSize > maxSize) {
                maxFreq = currFreq;
                maxSize = currSize;
            } else if(currSize == maxSize) {
               maxFreq = max(maxFreq, currFreq); 
            }
        }

        return grps[maxFreq];
    }
};