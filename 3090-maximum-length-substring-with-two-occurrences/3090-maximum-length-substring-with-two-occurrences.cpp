#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumLengthSubstring(std::string s) {
        // Frequency array for lowercase English letters
        std::vector<int> char_counts(26, 0);
        int left = 0;
        int max_length = 0;
        
        // Expand the window using the right pointer
        for (int right = 0; right < s.length(); ++right) {
            char_counts[s[right] - 'a']++;
            
            // Shrink the window from the left if the current character exceeds 2 occurrences
            while (char_counts[s[right] - 'a'] > 2) {
                char_counts[s[left] - 'a']--;
                left++;
            }
            
            // Track the maximum window size
            max_length = std::max(max_length, right - left + 1);
        }
        
        return max_length;
    }
};
