class Solution {
public:
    int minXor(vector<int>& nums, int k) {
    int n = nums.size();
        vector<int> pf(n+1,0);
        for(int i=1;i<=n;i++)
        {
        pf[i]=pf[i-1]^nums[i-1];
        }
                // Step 2: Initialize DP
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
        for (int i = 0; i <= n; i++) {
            dp[i][1] = pf[i];  // Base case
        }

        // Step 3: Fill DP table
        for (int parts = 2; parts <= k; parts++) {
            for (int end = parts; end <= n; end++) {
                for (int split = parts - 1; split < end; split++) {
                    int segmentXOR = pf[end] ^ pf[split];
                    int maxXOR = max(dp[split][parts - 1], segmentXOR);
                    dp[end][parts] = min(dp[end][parts], maxXOR);
                }
            }
        }

        return dp[n][k];
    }
};