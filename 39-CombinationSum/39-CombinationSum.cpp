// Last updated: 9/18/2025, 11:50:12 PM
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_set<int> s;
        int smallCom = -1;

        for(int i = 0; i < n1; i++) {
            if(s.find(nums1[i]) == s.end()) {
                s.insert(nums1[i]);
            }
        }

        for(int i = 0; i < n2; i++) {
            if(s.find(nums2[i]) != s.end()) {
                smallCom = nums2[i];
                break;
            }
        }

        return smallCom;
    }
};