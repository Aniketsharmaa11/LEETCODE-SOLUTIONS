class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b){
            return nums[a] < nums[b];
        });

        vector<int> s(n);
        for (int k = 0; k < n; k++) s[k] = nums[order[k]];

        vector<int> sortedPos(n);
        for (int k = 0; k < n; k++) sortedPos[order[k]] = k;

        // component ids based on consecutive gaps
        vector<int> compId(n, 0);
        for (int k = 1; k < n; k++) {
            if (s[k] - s[k-1] <= maxDiff) compId[k] = compId[k-1];
            else compId[k] = compId[k-1] + 1;
        }

        // reach[k] = farthest index r such that s[r] - s[k] <= maxDiff
        vector<int> reach(n);
        int r = 0;
        for (int k = 0; k < n; k++) {
            if (r < k) r = k;
            while (r + 1 < n && s[r+1] - s[k] <= maxDiff) r++;
            reach[k] = r;
        }

        // binary lifting
        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        LOG += 1;

        vector<vector<int>> up(LOG, vector<int>(n));
        up[0] = reach;
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[j][i] = up[j-1][up[j-1][i]];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int u = q[0], v = q[1];
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            int pu = sortedPos[u], pv = sortedPos[v];
            if (pu > pv) swap(pu, pv);

            if (compId[pu] != compId[pv]) {
                ans.push_back(-1);
                continue;
            }

            int cur = pu;
            long long steps = 0;
            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][cur] < pv) {
                    cur = up[j][cur];
                    steps += (1LL << j);
                }
            }
            ans.push_back((int)(steps + 1));
        }

        return ans;
    }
};