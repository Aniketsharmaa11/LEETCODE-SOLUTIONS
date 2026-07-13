#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> sequentialDigits(int low, int high) {
        std::string digits = "123456789";
        std::vector<int> result;
        
        // Loop through all possible lengths of sequential numbers (from 2 to 9 digits)
        for (int length = 2; length <= 9; ++length) {
            // Slide a window of 'length' across the master string
            for (int start = 0; start <= 9 - length; ++start) {
                std::string sub = digits.substr(start, length);
                int num = std::stoi(sub);
                
                // Keep the number if it falls within the inclusive range
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        
        return result;
    }
};
