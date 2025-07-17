// Last updated: 7/17/2025, 11:51:55 PM
class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        while(s.find(part) < s.length()) {
           
           s.erase(s.find(part), part.length());
        }

        return s;
    }
};