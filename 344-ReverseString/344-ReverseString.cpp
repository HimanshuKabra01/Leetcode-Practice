// Last updated: 7/16/2025, 7:52:53 PM
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();

        int i = 0;
        int j = n-1;

        while(i <= j) {
            swap(s[i], s[j]);

            i++;
            j--;
        }
    }
};