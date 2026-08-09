// Last updated: 8/9/2026, 12:28:25 PM
class Solution {
public:
    int passwordStrength(string password) {
        int ans = 0;
        unordered_set<char> st;

        for(int i = 0; i < password.size(); i++) {
            if(st.count(password[i])) continue;

            if(password[i] >= 'a' && password[i] <= 'z') {
                ans += 1;
                st.insert(password[i]);
            } else if(password[i] >= 'A' && password[i] <= 'Z') {
                ans += 2;
                st.insert(password[i]);
            } else if(password[i] >= '0' && password[i] <= '9') {
                ans += 3;
                st.insert(password[i]);
            } else if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$'){
                ans += 5;
                st.insert(password[i]);
            }
        }

        return ans;
    }
};