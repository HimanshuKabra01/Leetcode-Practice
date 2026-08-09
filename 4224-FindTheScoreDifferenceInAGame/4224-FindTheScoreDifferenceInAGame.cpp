// Last updated: 8/9/2026, 12:28:46 PM
class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();

        int scoreA = 0;
        int scoreB = 0;

        bool a = true;
        bool b = false;

        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 != 0) {
                if(a) {
                    b = true;
                    a = false;
                } else {
                    b = false;
                    a = true;
                }
            }

            if((i + 1) % 6 == 0) {
                if(a) {
                    b = true;
                    a = false;
                } else {
                    b = false;
                    a = true;
                }
            }

            if(a) {
                scoreA += nums[i];
            } else {
                scoreB += nums[i];
            }
        }

        return scoreA - scoreB;
    }
};