// Last updated: 9/9/2025, 11:24:21 PM
class Solution {
public:
    bool isPowerOfThree(int n) {
        if( n == 1) {
        return true;
        }

      if(n <= 0) {
        return false;
      }

      while(n > 1) {
        if(n % 3 != 0) {
            return false;
        }
        n /=3;
      }

      return true;  
    }
};