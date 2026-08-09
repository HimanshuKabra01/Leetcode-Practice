// Last updated: 8/9/2026, 12:32:10 PM
class Solution {
public:
    int countOperations(int num1, int num2) {
        int ops = 0;

        while(num1 != 0 && num2 != 0) {
            if(num1 > num2) {
                num1 -= num2;
            } else if(num2 >= num1) {
                num2 -= num1;
            }

            ops++;
        }

        return ops;
    }
};