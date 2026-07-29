class Solution {
public:
    static constexpr long long LIMIT = 1000001;

    long long binom(int n, int k) {
        if (k > n) return 0;
        k = min(k, n - k);

        long long res = 1;
        for (int i = 1; i <= k; i++) {
            res = res * (n - i + 1) / i;
            if (res >= LIMIT) return LIMIT;
        }
        return res;
    }

    long long countPerm(vector<int>& cnt) {
        int total = 0;
        for (int x : cnt) total += x;

        long long ans = 1;
        int rem = total;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) continue;
            ans *= binom(rem, cnt[i]);
            if (ans >= LIMIT) return LIMIT;
            rem -= cnt[i];
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {

        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> half(26, 0);
        string mid = "";

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2)
                mid.push_back(char('a' + i));

            half[i] = freq[i] / 2;
        }

        if (countPerm(half) < k)
            return "";

        string left = "";

        int len = s.size() / 2;

        while (len--) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                half[c]--;

                long long ways = countPerm(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};