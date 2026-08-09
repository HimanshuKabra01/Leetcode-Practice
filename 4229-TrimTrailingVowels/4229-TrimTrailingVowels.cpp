// Last updated: 8/9/2026, 12:28:44 PM
class Solution {
public:
    string trimTrailingVowels(string s) {
        unordered_set<char> st;

        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');

        string ans = "";

        while(s.length()){
            int len = s.size();

            char last = s[len - 1];

            if(st.count(last)) {
                s.resize(len-1);
                continue;
            } else {
                ans += s;
                break;
            }
        }

        return ans;
    }
};