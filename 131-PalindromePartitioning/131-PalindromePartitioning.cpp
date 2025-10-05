// Last updated: 10/5/2025, 11:47:28 AM
class Solution {
public:
    bool isValid(string s) {
        string s2 = s;

        reverse(s2.begin(), s2.end());

        if(s2 == s) {
            return true;
        }

        return false;
    }

    void getAllPart(string s, vector<vector<string>>& ans, vector<string>& partitions){
        if(s.size() == 0) {
            ans.push_back({partitions});
        }

        for(int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i+1);

            if(isValid(part)){
                partitions.push_back(part);

                getAllPart(s.substr(i+1), ans, partitions);

                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
       vector<vector<string>> ans;
       vector<string> partitions;

       getAllPart(s, ans, partitions);

       return ans;
    }
};