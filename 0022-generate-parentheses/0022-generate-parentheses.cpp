#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string current_string = "";
        backtrack(result, current_string, 0, 0, n);
        return result;
    }

private:
    void backtrack(std::vector<std::string>& result, std::string& current_string, int open_count, int close_count, int max_pairs) {
        // Base case: if the string reaches the required length (2 * n)
        if (current_string.length() == 2 * max_pairs) {
            result.push_back(current_string);
            return;
        }

        // Rule 1: Add an open parenthesis if we haven't reached the limit 'n'
        if (open_count < max_pairs) {
            current_string.push_back('(');
            backtrack(result, current_string, open_count + 1, close_count, max_pairs);
            current_string.pop_back(); // Backtrack step: remove the character
        }

        // Rule 2: Add a close parenthesis if it matches a previously opened one
        if (close_count < open_count) {
            current_string.push_back(')');
            backtrack(result, current_string, open_count, close_count + 1, max_pairs);
            current_string.pop_back(); // Backtrack step: remove the character
        }
    }
};
