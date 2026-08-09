// Last updated: 8/9/2026, 12:39:33 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        vector<int> ans;
        int n = arr.size();

        int st = 0;
        int end = n - 1;

        while(st < end) {
            if((arr[st] + arr[end]) == target) {
                ans.push_back(st+1);
                ans.push_back(end+1);
                break;
            } else if((arr[st] + arr[end]) > target) {
                end--;
            } else if((arr[st] + arr[end]) < target) {
                st++;
            }
        }

        return ans;
    }
};