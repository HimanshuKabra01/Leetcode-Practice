// Last updated: 8/30/2025, 9:54:25 PM
class Solution {
public:
    int findNumbers(vector<int>& nums) {
       int n = nums.size();
       int evenDig = 0;

       for(int num : nums) {
            int dig = 0;
            while(num > 0) {
                dig++;
                num /= 10;
            }

            if(dig % 2 == 0) {
                evenDig++;
            }
       } 

       return evenDig; 
    }
};