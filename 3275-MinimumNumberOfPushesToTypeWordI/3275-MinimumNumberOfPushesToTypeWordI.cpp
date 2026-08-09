// Last updated: 8/9/2026, 12:31:41 PM
class Solution {
public:
    int minimumPushes(string word) {
    if(word.size() <= 8) {
        return word.size();
    } else if(word.size() <= 16) {
        int rem = word.size() - 8;
        return 8 + (rem * 2);
    } else if(word.size() <= 24) {
        int rem = word.size() - 16;
        return 24 + (rem * 3);
    } else {
        int rem = word.size() - 24;
        return 48 + (rem * 4);
    }
}
};