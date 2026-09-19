#include <algorithm>

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find the closest point on the rectangle to the circle's center
        int closestX = std::max(x1, std::min(xCenter, x2));
        int closestY = std::max(y1, std::min(yCenter, y2));
        
        // Calculate the vector components from the center to this closest point
        int distanceX = closestX - xCenter;
        int distanceY = closestY - yCenter;
        
        // Check if the squared distance is within the squared radius bounds
        return (distanceX * distanceX) + (distanceY * distanceY) <= (radius * radius);
    }
};
