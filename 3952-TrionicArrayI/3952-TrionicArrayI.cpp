// Last updated: 8/9/2026, 12:30:44 PM
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr;
        for(int i = 0; i < n-1; i++) {
            int diff = nums[i+1] - nums[i];

            arr.push_back(diff);
        }

        int m = arr.size();
        int p = -1;
        int q = -1;

        for(int i = 0; i < m; i++) {
            if(arr[i] < 0) {
                p = i;
                break;
            }
        }

        for(int i = p+1; i < m; i++) {
            if(arr[i] > 0) {
                q = i;
                break;
            }
        }

        if(p <= 0 || q == -1) {
            return false;
        }

        bool possible = true;
        for(int i = 0; i < p; i++) {
            if(arr[i] <= 0) {
                possible = false;
            }
        }

        for(int i = p; i < q; i++) {
            if(arr[i] >= 0) {
                possible = false;
            }
        }

        for(int i = q; i < m; i++) {
            if(arr[i] <= 0) {
                possible = false;
            }
        }

        return possible;
    }
};