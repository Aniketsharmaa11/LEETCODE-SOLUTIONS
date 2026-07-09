class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);

        int i = s.size() - 2;

        // Step 1: Find first decreasing digit
        while (i >= 0 && s[i] >= s[i + 1])
            i--;

        if (i < 0)
            return -1;

        // Step 2: Find just larger digit from the right
        int j = s.size() - 1;
        while (s[j] <= s[i])
            j--;

        swap(s[i], s[j]);

        // Step 3: Reverse the suffix
        reverse(s.begin() + i + 1, s.end());

        long long ans = stoll(s);

        return (ans > INT_MAX) ? -1 : ans;
    }
};