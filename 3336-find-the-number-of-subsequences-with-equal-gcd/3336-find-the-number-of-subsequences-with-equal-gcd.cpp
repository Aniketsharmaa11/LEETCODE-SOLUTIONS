#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int subsequencePairCount(std::vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        
        // Dynamic boundary scaling based on the highest integer
        int max_val = 0;
        for (int num : nums) {
            max_val = std::max(max_val, num);
        }
        
        int size = max_val + 1;
        // Flat array representation: (g1 * size + g2) 
        std::vector<int> dp(size * size, 0);
        std::vector<int> next_dp(size * size, 0);
        
        // Base case: Both sequences start out empty with implicit GCD = 0
        dp[0] = 1;
        
        for (int num : nums) {
            // Choice 3: Skip current number (inherit old counts)
            next_dp = dp;
            
            for (int g1 = 0; g1 <= max_val; ++g1) {
                for (int g2 = 0; g2 <= max_val; ++g2) {
                    int current_count = dp[g1 * size + g2];
                    if (current_count == 0) continue;
                    
                    // Choice 1: Add num to the first subsequence (seq1)
                    int ng1 = std::gcd(g1, num);
                    int idx1 = ng1 * size + g2;
                    next_dp[idx1] = (next_dp[idx1] + current_count) % MOD;
                    
                    // Choice 2: Add num to the second subsequence (seq2)
                    int ng2 = std::gcd(g2, num);
                    int idx2 = g1 * size + ng2;
                    next_dp[idx2] = (next_dp[idx2] + current_count) % MOD;
                }
            }
            dp = next_dp;
        }
        
        // Accumulate matching states where g1 == g2 and g1 > 0
        int total_pairs = 0;
        for (int g = 1; g <= max_val; ++g) {
            total_pairs = (total_pairs + dp[g * size + g]) % MOD;
        }
        
        return total_pairs;
    }
};
