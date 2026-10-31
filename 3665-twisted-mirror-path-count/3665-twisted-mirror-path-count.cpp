#include <vector>
#include <cstring>

class Solution {
private:
    int m, n;
    long long MOD = 1e9 + 7;
    // memo[r][c][dir]: dir=0 for Right, dir=1 for Down
    int memo[505][505][2];

    // solve returns the number of valid paths from empty cell (r, c) 
    // when choosing to move in direction 'dir'
    long long solve(int r, int c, int dir, const std::vector<std::vector<int>>& grid) {
        // Return cached result if already calculated
        if (memo[r][c][dir] != -1) {
            return memo[r][c][dir];
        }

        int nr = r;
        int nc = c;
        int current_dir = dir;

        // 1. Take the initial step in the chosen direction
        if (current_dir == 0) {
            nc++;
        } else {
            nr++;
        }

        // 2. If the initial step goes out of bounds, it's an invalid path
        if (nr >= m || nc >= n) {
            return 0;
        }

        // 3. Follow the reflection chain if we hit consecutive mirror cells (grid == 1)
        while (grid[nr][nc] == 1) {
            if (current_dir == 0) { // Moving Right into a mirror reflects DOWN
                nr++;
                current_dir = 1;
            } else { // Moving Down into a mirror reflects RIGHT
                nc++;
                current_dir = 0;
            }

            // If a reflection bounces the robot out of bounds, the path is invalid
            if (nr >= m || nc >= n) {
                return 0;
            }
        }

        // 4. Now the robot has safely landed on an empty cell (nr, nc)
        // Base Case: If this empty cell is the destination corner
        if (nr == m - 1 && nc == n - 1) {
            return 1;
        }

        // Otherwise, from this new empty cell, the robot can choose to go either Right or Down
        long long paths = (solve(nr, nc, 0, grid) + solve(nr, nc, 1, grid)) % MOD;

        return memo[r][c][dir] = paths;
    }

public:
    int uniquePaths(std::vector<std::vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size(); // Corrected to properly support rectangular grids
        
        // Initialize the memoization table with -1
        std::memset(memo, -1, sizeof(memo));

        // From the start cell (0,0), the robot can initially choose to go either Right (0) or Down (1)
        long long total_paths = (solve(0, 0, 0, grid) + solve(0, 0, 1, grid)) % MOD;
        
        return total_paths;
    }
};
