#include <vector>

class Solution {
public:
    int maxSum(std::vector<int>& nums, int k) {
        long long MOD = 1e9 + 7;
        std::vector<int> bit_counts(30, 0);
        
        // Step 1: Count the total number of 1s at each bit position
        for (int num : nums) {
            for (int i = 0; i < 30; ++i) {
                if ((num >> i) & 1) {
                    bit_counts[i]++;
                }
            }
        }
        
        // Step 2 & 3: Greedily construct the k largest numbers and sum their squares
        long long total_sum_squares = 0;
        
        for (int j = 0; j < k; ++j) {
            long long current_num = 0;
            for (int i = 0; i < 30; ++i) {
                if (bit_counts[i] > 0) {
                    current_num |= (1 << i);
                    bit_counts[i]--;
                }
            }
            
            // Add the square of the constructed number to the total
            total_sum_squares = (total_sum_squares + current_num * current_num) % MOD;
        }
        
        return total_sum_squares;
    }
};
