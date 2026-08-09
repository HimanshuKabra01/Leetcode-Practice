// Last updated: 8/9/2026, 12:37:51 PM
class Solution {
public:
    bool isPowerOfFour(int n) {

      if( n == 1) {
        return true;
      }

      if(n <= 0) {
        return false;
      }

      while(n > 1) {
        if(n % 4 != 0) {
            return false;
        }
        n /= 4;
      }

      return true;  
    }
};