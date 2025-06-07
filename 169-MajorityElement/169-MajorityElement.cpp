// Last updated: 6/7/2025, 5:39:25 PM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // for(int val : nums) {
        //     int freq = 0;    
        int n = nums.size();
        //     for(int elem : nums) {
        //         if(elem == val) {
        //             freq++;
        //         }
        //     }
        //     if(freq > n/2){
        //         return val;
        //     }
        // }
        // return -1;

        //sort
        sort(nums.begin(), nums.end());

        //freq

        int freq = 1, ans = nums[0];
        for(int i=1; i < n; i++) {
            if(nums[i] == nums[i-1]) {
                freq++;
            } else{
                freq = 1, ans = nums[i];
            }
            if(freq > n/2) {
                return ans;
            }
        }
        return ans;
    }
};