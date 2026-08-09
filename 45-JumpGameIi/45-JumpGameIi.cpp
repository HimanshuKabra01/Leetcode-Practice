// Last updated: 8/9/2026, 12:42:26 PM
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        int currEnd = 0;

        if(n==1) {
            return 0;
        }

        int far = 0;

        for(int i = 0; i < n; i++) {
            int curr = i + nums[i];

            far = max(curr, far);

            if(i == currEnd && i != n-1) {
                ans++;
                currEnd = far;
            }
        }

        return ans;
    }
};