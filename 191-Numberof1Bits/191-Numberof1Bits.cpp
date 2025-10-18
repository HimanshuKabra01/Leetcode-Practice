// Last updated: 10/19/2025, 2:12:06 AM
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