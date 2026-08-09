// Last updated: 8/9/2026, 12:37:40 PM
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;

        sort(nums1.begin(), nums1.end());
        unordered_map<int, int> m;

        for(int i = 0; i < n; i++) {
            m[nums1[i]]++;
        }

        for(int i = 0; i < n2; i++) {
            if(m[nums2[i]] > 0) {
                m[nums2[i]]--;
                ans.push_back(nums2[i]);
            }
        }

        return ans;
    }
};