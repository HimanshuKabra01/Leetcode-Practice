// Last updated: 9/7/2025, 5:39:07 PM
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;

        sort(nums1.begin(), nums1.end());
        unordered_set<int> s;

        for(int i = 0; i < n; i++) {
            if(s.find(nums1[i]) == s.end()){
                s.insert(nums1[i]);
            }
        }

        for(int i = 0; i < n2; i++) {
            if(s.find(nums2[i]) != s.end()) {
                ans.push_back(nums2[i]);
                s.erase(nums2[i]);
            }
        }

        return ans;
    }
};