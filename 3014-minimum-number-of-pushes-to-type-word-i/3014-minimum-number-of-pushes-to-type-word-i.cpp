#include <string>

class Solution {
public:
    int minimumPushes(std::string word) {
        int n = word.length();
        int totalPushes = 0;
        
        // Since all letters are distinct, we can distribute them sequentially
        for (int i = 0; i < n; ++i) {
            totalPushes += (i / 8) + 1;
        }
        
        return totalPushes;
    }
};
