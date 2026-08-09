// Last updated: 8/9/2026, 12:30:24 PM
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