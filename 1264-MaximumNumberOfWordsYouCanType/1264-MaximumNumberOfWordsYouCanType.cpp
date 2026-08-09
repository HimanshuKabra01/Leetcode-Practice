// Last updated: 8/9/2026, 12:33:57 PM
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int count = 0;

        unordered_set<char> word;
        for(int i = 0; i <= text.size(); i++) {
            if(i == text.size() || text[i] == ' ') {
                bool isBroken = false;
                for(char c : brokenLetters) {
                    if(word.find(c) != word.end()) {
                        isBroken = true;
                        break;
                    }
                }
                if(!isBroken && !word.empty()) count++;
                word.clear();
            } else {
                word.insert(text[i]);
            }
        }

        return count;
    }
};