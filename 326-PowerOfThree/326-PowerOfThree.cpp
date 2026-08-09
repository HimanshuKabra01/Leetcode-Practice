// Last updated: 8/9/2026, 12:37:55 PM
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