// Last updated: 9/17/2025, 11:54:42 PM
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        int n = arr.size();
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for(int i = 0; i < n; i++) {
            string original = arr[i];
            string sortedStr = arr[i];

            sort(sortedStr.begin(), sortedStr.end());

            mp[sortedStr].push_back(original);
        }

        for(auto &entry : mp) {
            ans.push_back(entry.second);
        }

        return ans;
    }
};