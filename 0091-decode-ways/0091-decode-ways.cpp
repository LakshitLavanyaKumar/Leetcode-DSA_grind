class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') return 0;

        vector<int> dp(n + 1, 0);
        dp[0] = 1;       // empty string
        dp[1] = 1;       // since s[0] != '0'

        for (int i = 2; i <= n; ++i) {
            // One digit
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }

            // Two digits
            int twoDigit = stoi(s.substr(i - 2, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};
