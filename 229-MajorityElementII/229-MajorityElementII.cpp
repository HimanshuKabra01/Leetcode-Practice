// Last updated: 11/5/2025, 6:09:31 PM
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        int el1 = 0, el2 = 0;
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0 ; i < n ; i++){
            if(el1 == nums[i]) cnt1++;
            else if(el2 == nums[i]) cnt2++;
            else if(cnt1 == 0){
                el1 = nums[i];
                cnt1++;
            }
            else if(cnt2 == 0){
                el2 = nums[i]; 
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0,cnt2 = 0;
        for(int i = 0 ; i < n ; i++){
            if(el1 == nums[i]) cnt1++;
            else if(el2 == nums[i]) cnt2++;
        }
        if(cnt1 > n/3) v.push_back(el1);
        if(cnt2 > n/3) v.push_back(el2);
        return v;
    }
};