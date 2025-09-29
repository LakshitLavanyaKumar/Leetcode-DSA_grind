class Solution {
public:
    #define ll long long
    const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        vector<vector<ll>> prev(m+1, vector<ll>(2,0)), curr(m+1, vector<ll>(2,0));

        // Base case: arrays of length 1
        for (int j=1; j<=m; j++) {
            prev[j][0] = prev[j][1] = 1;
        }

        for (int len=2; len<=n; len++) {
            // prefix sums
            vector<ll> pref0(m+2,0), pref1(m+2,0);
            for (int j=1; j<=m; j++) {
                pref0[j] = (pref0[j-1] + prev[j][0]) % MOD;
                pref1[j] = (pref1[j-1] + prev[j][1]) % MOD;
            }

            for (int j=1; j<=m; j++) {
                curr[j][1] = pref0[j-1];                         // prev < j
                curr[j][0] = ( (pref1[m] - pref1[j]) % MOD + MOD ) % MOD; // prev > j
            }

            swap(prev, curr);
            fill(curr.begin(), curr.end(), vector<ll>(2,0)); // reset
        }

        ll ans = 0;
        for (int j=1; j<=m; j++) {
            ans = (ans + prev[j][0] + prev[j][1]) % MOD;
        }
        return ans;
    }
};
