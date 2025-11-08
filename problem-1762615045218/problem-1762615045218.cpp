// Last updated: 11/8/2025, 8:47:25 PM
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prefix(n+1);

        int count = 0;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] != target) {
                count--;
            } else {
                count++;
            }

            prefix[i+1] = count;
        }

        for(int i = 0; i < n+1; i++) {
            for(int j = i + 1; j < n+1; j++) {
                if(prefix[i] < prefix[j]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};