// Last updated: 11/22/2025, 8:13:56 PM
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int wavi = 0;

        for(int i = num1; i <= num2; i++) {
            string num = to_string(i);

            for(int j = 1; j < num.size()-1; j++) {

                if(num[j] > num[j-1] && num[j] > num[j+1]) {
                    wavi++;
                } else if(num[j] < num[j-1] && num[j] < num[j+1]) {
                    wavi++;
                }
            }
        }

        return wavi;
    }
};