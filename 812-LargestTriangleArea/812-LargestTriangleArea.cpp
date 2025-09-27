// Last updated: 9/27/2025, 7:01:47 PM
class Solution {
public:
    unordered_set<char> s;
    bool hasVowel(const string& s) {
        string vowels = "aeiouAEIOU";
        for(char c : s) {
            if(vowels.find(c) != string::npos)
                return true;
        }
        return false;
    }

    bool hasConsonant(const string& s) {
        string vowels = "aeiou";
        for (char c : s) {
            if (isalpha(c)) {
                char lower = tolower(c);
                if (vowels.find(lower) == string::npos)
                    return true;
            }
        }
        return false;
    }

    bool isValid(string word) {
        int n = word.size();
       for(int i = 0; i < n; i++) {
        if(!isalnum(word[i])) {
            return false;
        }
        if(s.find(word[i]) == s.end()) {
            s.insert(word[i]);
        }
       }

       if(n >= 3 && hasVowel(word) && hasConsonant(word)) {
        return true;
       }

       return false;
    }
};