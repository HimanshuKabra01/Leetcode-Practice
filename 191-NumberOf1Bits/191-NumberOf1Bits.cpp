// Last updated: 8/9/2026, 12:39:14 PM
class Solution {
public:
    int hammingWeight(int n) {
        vector<int> freq(2, 0);
        
        while(n != 0) {
          int digit = n % 2;

          if(digit == 0) {
            freq[0]++;
          } else {
            freq[1]++;
          }

          n /= 2;
        }

        return freq[1];
    }
};