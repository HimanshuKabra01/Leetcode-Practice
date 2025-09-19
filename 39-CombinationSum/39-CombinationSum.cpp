// Last updated: 9/19/2025, 4:15:22 PM
class Solution {
public:
    set<vector<int>> s;
    void getComb(vector<int>& arr, vector<vector<int>>& ans, int idx, vector<int>& combin, int tar) {
        int n = arr.size();
        if(idx == n || tar < 0) {
            return;
        }

        if(tar == 0) {
            if(s.find(combin) == s.end()) {
                ans.push_back({combin});
                s.insert(combin);
            }

            return;
        }

        combin.push_back(arr[idx]);

        //single
        getComb(arr, ans, idx+1, combin, tar-arr[idx]);
        //multiple
        getComb(arr, ans, idx, combin, tar-arr[idx]);

        //backtracking
        combin.pop_back();
        getComb(arr, ans, idx+1, combin, tar);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combin;

        getComb(arr, ans, 0, combin, target);

        return ans;
    }
};