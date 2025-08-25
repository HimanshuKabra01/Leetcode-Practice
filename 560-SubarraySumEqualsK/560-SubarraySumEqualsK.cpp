// Last updated: 8/26/2025, 12:50:20 AM
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // //brute force
        int n = nums.size();
        // int count = 0;

        // for(int i = 0; i < n; i++) {
        //     int sum = 0;
        //     for(int j = i; j < n; j++) {
        //         sum += nums[j];

        //         if(sum == k) count++;
        //     }
        // }

        // return count;

        //Optimized Approach
        //Prefix sum
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        int count = 0;

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }

        unordered_map<int, int> m;
        for(int j = 0; j < n; j++) {
            int val = prefix[j] - k;

            if(prefix[j] == k) {
                count++;
            }

            if(m.find(val) != m.end()) {
                count += m[val];
            }

            if(m.find(prefix[j]) == m.end()) {
                m[prefix[j]] = 0;
            }

            m[prefix[j]]++;
        }

        return count;
    }
};