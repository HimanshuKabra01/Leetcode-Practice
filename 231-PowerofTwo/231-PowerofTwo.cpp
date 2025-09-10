// Last updated: 9/10/2025, 7:55:08 PM
class Solution {
public:
    bool isPowerOfTwo(int n) {
       if( n == 1) {
        return true;
        }

      if(n <= 0) {
        return false;
      }

      while(n > 1) {
        if(n % 2 != 0) {
            return false;
        }
        n /=2;
      }

      return true;  
    }
};