#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();
        int q = queries.size();
        
        // Sort logs chronologically by time
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        // Pair each query with its original index to preserve output order
        vector<pair<int, int>> sortedQueries(q);
        for (int i = 0; i < q; ++i) {
            sortedQueries[i] = {queries[i], i};
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        
        vector<int> ans(q);
        vector<int> freq(n + 1, 0); // Frequency of requests per server in current window
        int activeServers = 0;       // Count of servers with at least 1 request
        int left = 0, right = 0;     // Sliding window pointers for logs
        
        for (const auto& [endTime, originalIdx] : sortedQueries) {
            int startTime = endTime - x;
            
            // Expand right pointer: include logs with time <= endTime
            while (right < m && logs[right][1] <= endTime) {
                int serverId = logs[right][0];
                if (freq[serverId] == 0) {
                    activeServers++;
                }
                freq[serverId]++;
                right++;
            }
            
            // Shrink left pointer: exclude logs with time < startTime
            while (left < m && logs[left][1] < startTime) {
                int serverId = logs[left][0];
                freq[serverId]--;
                if (freq[serverId] == 0) {
                    activeServers--;
                }
                left++;
            }
            
            // Servers with 0 requests = Total servers - Active servers
            ans[originalIdx] = n - activeServers;
        }
        
        return ans;
    }
};
