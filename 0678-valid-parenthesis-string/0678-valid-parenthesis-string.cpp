#include <string>
#include <algorithm>

class Solution {
public:
    bool checkValidString(std::string s) {
        int cmin = 0; // Minimum possible open '('
        int cmax = 0; // Maximum possible open '('
        
        for (char c : s) {
            if (c == '(') {
                cmin++;
                cmax++;
            } else if (c == ')') {
                cmin--;
                cmax--;
            } else if (c == '*') {
                cmin--; // If treated as ')'
                cmax++; // If treated as '('
            }
            
            // If max possible open '(' is negative, there are too many ')'
            if (cmax < 0) {
                return false;
            }
            
            // cmin cannot drop below 0 because we can't carry over a deficit
            if (cmin < 0) {
                cmin = 0;
            }
        }
        
        // If 0 is within our possible range of open parentheses, it's valid
        return cmin == 0;
    }
};
