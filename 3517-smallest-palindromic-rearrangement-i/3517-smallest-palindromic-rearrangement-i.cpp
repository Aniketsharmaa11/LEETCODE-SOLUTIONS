class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26, 0);

        for (char ch : s)
            cnt[ch - 'a']++;

        string left = "";
        char mid = '\0';

        for (int i = 0; i < 26; i++) {
            left.append(cnt[i] / 2, 'a' + i);

            if (cnt[i] % 2 == 1)
                mid = 'a' + i;
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid != '\0')
            return left + mid + right;

        return left + right;
    }
};