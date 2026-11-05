#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int findTheDistanceValue(std::vector<int>& arr1, std::vector<int>& arr2, int d) {
        // Sort arr2 to enable binary search
        std::sort(arr2.begin(), arr2.end());
        int distance_value = 0;
        
        for (int x : arr1) {
            // Find the first element in arr2 that is >= x - d
            auto it = std::lower_bound(arr2.begin(), arr2.end(), x - d);
            
            // If such an element exists and it is also <= x + d,
            // then it falls within the invalid range |x - arr2[j]| <= d
            if (it != arr2.end() && *it <= x + d) {
                continue;
            }
            
            // If no element in arr2 is within [x - d, x + d], increment count
            distance_value++;
        }
        
        return distance_value;
    }
};
