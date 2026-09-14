#include <vector>

class Solution {
public:
    bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2) {
        // rec1 = [x1, y1, x2, y2]
        // rec2 = [x3, y3, x4, y4]
        
        // Check if one rectangle is completely outside the other
        return !(rec1[2] <= rec2[0] || // rec1 is left of rec2
                 rec1[0] >= rec2[2] || // rec1 is right of rec2
                 rec1[3] <= rec2[1] || // rec1 is below rec2
                 rec1[1] >= rec2[3]);  // rec1 is above rec2
    }
};
