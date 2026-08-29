#include <string>
#include <vector>

class Solution {
public:
    std::string smallestSubsequence(std::string s) {
        std::vector<int> count(26, 0);
        std::vector<bool> visited(26, false);
        std::string result = ""; // Acting as our stack
        
        // Step 1: Count the frequency of each character
        for (char ch : s) {
            count[ch - 'a']++;
        }
        
        // Step 2: Iterate through the string to build the result
        for (char ch : s) {
            count[ch - 'a']--; // Decrement the remaining count for the current character
            
            // If the character is already in our result, skip it
            if (visited[ch - 'a']) {
                continue;
            }
            
            // Maintain the monotonic property of the stack:
            // Pop the last character if it's larger than the current character
            // AND if it appears again later in the string.
            while (!result.empty() && result.back() > ch && count[result.back() - 'a'] > 0) {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            // Add the current character to the result and mark it as visited
            result.push_back(ch);
            visited[ch - 'a'] = true;
        }
        
        return result;
    }
};
