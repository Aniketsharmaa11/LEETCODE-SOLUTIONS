#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int totalElements = m * n;
        
        // Optimize k to handle rotations larger than total elements
        k = k % totalElements;
        
        // Create a flat 1D vector to hold all grid elements
        std::vector<int> flatGrid;
        flatGrid.reserve(totalElements);
        
        for (const auto& row : grid) {
            flatGrid.insert(flatGrid.end(), row.begin(), row.end());
        }
        
        // Create the result grid initialized to the correct size
        std::vector<std::vector<int>> result(m, std::vector<int>(n));
        
        // Reconstruct the 2D grid using shifted positions
        for (int i = 0; i < totalElements; ++i) {
            // Find the new 1D index after shifting k times
            int newIndex = (i + k) % totalElements;
            
            // Map the new index back to 2D row and column positions
            int newRow = newIndex / n;
            int newCol = newIndex % n;
            
            result[newRow][newCol] = flatGrid[i];
        }
        
        return result;
    }
};
