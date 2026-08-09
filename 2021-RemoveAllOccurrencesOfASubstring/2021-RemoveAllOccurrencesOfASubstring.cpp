// Last updated: 8/9/2026, 12:32:43 PM
class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        while(s.find(part) < s.length()) {
           
           s.erase(s.find(part), part.length());
        }

        return s;
    }
};