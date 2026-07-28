class Solution {
public:
    bool isValid(string s) {
        string st;

        for (char ch : s) {
            st.push_back(ch);

            if (st.size() >= 3 &&
                st.substr(st.size() - 3) == "abc") {
                st.erase(st.size() - 3);
            }
        }

        return st.empty();
    }
};