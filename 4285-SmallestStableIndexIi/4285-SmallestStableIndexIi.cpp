// Last updated: 8/9/2026, 12:28:27 PM
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxi(n);
        vector<int> mini(n);

        maxi[0] = nums[0];
        for(int i = 1; i < n; i++) {
            if(nums[i] > maxi[i-1]) {
                maxi[i] = nums[i];
            } else {
                maxi[i] = maxi[i-1];
            }
        }

        mini[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] < mini[i+1]) {
                mini[i] = nums[i];
            } else {
                mini[i] = mini[i+1];
            }
        }
        int ans = -1;
        for(int i = 0; i < n; i++) {
            int score = maxi[i]-mini[i];

            if(score <= k) {
                ans = i;
                break;
            }
        }

        return ans;
    }
};