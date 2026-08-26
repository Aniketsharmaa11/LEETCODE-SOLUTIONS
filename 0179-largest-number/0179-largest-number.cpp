#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string largestNumber(std::vector<int>& nums) {
        // Step 1: Convert all integers to strings
        std::vector<std::string> str_nums;
        for (int num : nums) {
            str_nums.push_back(std::to_string(num));
        }
        
        // Step 2: Sort strings using a custom lambda comparator
        // If (a + b) is greater than (b + a), 'a' should come before 'b'
        std::sort(str_nums.begin(), str_nums.end(), [](const std::string& a, const std::string& b) {
            return a + b > b + a;
        });
        
        // Step 3: Handle the edge case where the largest number is "0"
        // If the first element after sorting is "0", the entire number is 0
        if (str_nums[0] == "0") {
            return "0";
        }
        
        // Step 4: Concatenate all strings to form the final result
        std::string result = "";
        for (const std::string& str : str_nums) {
            result += str;
        }
        
        return result;
    }
};
