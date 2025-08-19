class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp; // value -> best length ending with that value
        int best = 0;
        for (int x : arr) {
            int prev = x - difference;
            int len = 1;
            if (auto it = dp.find(prev); it != dp.end()) len = it->second + 1;
            // in case x repeats, keep the maximum length
            dp[x] = max(dp[x], len);
            if (dp[x] > best) best = dp[x];
        }
        return best;
    }
};
