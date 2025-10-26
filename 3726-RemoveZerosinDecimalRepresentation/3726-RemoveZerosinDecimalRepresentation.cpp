// Last updated: 10/26/2025, 10:38:53 AM
class Solution {
public:
    long long removeZeros(long long n) {
      string s = to_string(n);
      int size = s.size();
      string withoutZero = "";

      for(int i = 0; i < size; i++) {
        if(s[i] != '0') {
            withoutZero += s[i];
        }
      }

      long long ans = stoll(withoutZero);

      return ans;  
    }
};