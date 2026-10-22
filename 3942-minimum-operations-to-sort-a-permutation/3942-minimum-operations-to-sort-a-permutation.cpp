#include <vector>
#include <algorithm>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        // Locate the index of element 0
        int idx_0 = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                idx_0 = i;
                break;
            }
        }

        // 1. Check if it's an increasing cyclic shift
        bool is_inc = true;
        for (int k = 0; k < n; ++k) {
            if (nums[(idx_0 + k) % n] != k) {
                is_inc = false;
                break;
            }
        }

        if (is_inc) {
            int i = nums[0];
            if (i == 0) return 0;
            return std::min(n - i, i + 2);
        }

        // 2. Check if it's a decreasing cyclic shift
        bool is_dec = true;
        for (int k = 0; k < n; ++k) {
            if (nums[(idx_0 - k + n) % n] != k) {
                is_dec = false;
                break;
            }
        }

        if (is_dec) {
            int j = nums[0];
            return std::min(j + 2, n - j);
        }

        // 3. Invalid configuration
        return -1;
    }
};
