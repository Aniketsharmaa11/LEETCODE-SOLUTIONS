#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    // Constants for double hashing to prevent collisions
    const long long MOD1 = 1e9 + 7;
    const long long MOD2 = 1e9 + 9;
    const long long BASE1 = 31;
    const long long BASE2 = 37;

    vector<long long> pow1, pow2;
    vector<long long> pref1, pref2;
    vector<long long> suff1, suff2;
    
    vector<int> start_idx, end_idx;
    vector<vector<int>> adj;
    string flat_str = "";
    int timer = 0;

    // First DFS pass to flatten the tree in the specified traversal order
    void flattenTree(int u, const string& s) {
        start_idx[u] = timer;
        for (int v : adj[u]) {
            flattenTree(v, s);
        }
        flat_str += s[u];
        end_idx[u] = timer;
        timer++;
    }

    // Helper function to check if a substring flat_str[L...R] is a palindrome
    bool isPalindrome(int L, int R) {
        if (L > R) return true;

        // Forward hash 1
        long long hash_f1 = (pref1[R + 1] - (pref1[L] * pow1[R - L + 1]) % MOD1 + MOD1) % MOD1;
        // Backward hash 1
        long long hash_b1 = (suff1[L] - (suff1[R + 1] * pow1[R - L + 1]) % MOD1 + MOD1) % MOD1;

        if (hash_f1 != hash_b1) return false;

        // Forward hash 2
        long long hash_f2 = (pref2[R + 1] - (pref2[L] * pow2[R - L + 1]) % MOD2 + MOD2) % MOD2;
        // Backward hash 2
        long long hash_b2 = (suff2[L] - (suff2[R + 1] * pow2[R - L + 1]) % MOD2 + MOD2) % MOD2;

        return hash_f2 == hash_b2;
    }

public:
    vector<bool> findAnswer(vector<int>& parent, string s) {
        int n = parent.size();
        
        // Initialize adjacency list
        adj.assign(n, vector<int>());
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        // Flatten the tree traversal
        start_idx.resize(n);
        end_idx.resize(n);
        flat_str = "";
        timer = 0;
        flattenTree(0, s);

        // Precompute powers for rolling hashes
        pow1.resize(n + 1, 1);
        pow2.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow1[i] = (pow1[i - 1] * BASE1) % MOD1;
            pow2[i] = (pow2[i - 1] * BASE2) % MOD2;
        }

        // Compute prefix hashes (Forward)
        pref1.resize(n + 1, 0);
        pref2.resize(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref1[i + 1] = (pref1[i] * BASE1 + (flat_str[i] - 'a' + 1)) % MOD1;
            pref2[i + 1] = (pref2[i] * BASE2 + (flat_str[i] - 'a' + 1)) % MOD2;
        }

        // Compute suffix hashes (Backward)
        suff1.resize(n + 1, 0);
        suff2.resize(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suff1[i] = (suff1[i + 1] * BASE1 + (flat_str[i] - 'a' + 1)) % MOD1;
            suff2[i] = (suff2[i + 1] * BASE2 + (flat_str[i] - 'a' + 1)) % MOD2;
        }

        // Construct the answer array
        vector<bool> answer(n);
        for (int i = 0; i < n; ++i) {
            answer[i] = isPalindrome(start_idx[i], end_idx[i]);
        }

        return answer;
    }
};
