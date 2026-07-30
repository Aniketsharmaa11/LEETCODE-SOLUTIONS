#pragma GCC optimize("O3")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <vector>
#include <climits>

class Solution {
public:
    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k) {
        // Distance array initialized to infinity
        std::vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // At most k stops means at most k + 1 edges
        for (int i = 0; i <= k; ++i) {
            std::vector<int> temp = dist;
            for (const auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int price = flight[2];

                if (dist[u] != INT_MAX && dist[u] + price < temp[v]) {
                    temp[v] = dist[u] + price;
                }
            }
            dist = temp; // Update standard distances after this level
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
