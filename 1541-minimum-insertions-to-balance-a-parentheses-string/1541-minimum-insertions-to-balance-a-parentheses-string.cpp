#include <string>
#include <iostream>

class Solution {
public:
    int minInsertions(std::string s) {
        int insertions = 0;
        int needed_rights = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                needed_rights += 2;
                
                // If we have an odd number of needed rights, it means the 
                // previous '(' only got one ')'. Insert a ')' to fix it.
                if (needed_rights % 2 != 0) {
                    insertions++;
                    needed_rights--;
                }
            } else { // s[i] == ')'
                if (needed_rights == 0) {
                    // No matching open parenthesis. Insert an opening '('.
                    // It requires 2 right parentheses, and this current ')' fulfills 1.
                    insertions++; 
                    needed_rights += 1; 
                } else {
                    needed_rights--;
                }
            }
        }
        
        return insertions + needed_rights;
    }
};
