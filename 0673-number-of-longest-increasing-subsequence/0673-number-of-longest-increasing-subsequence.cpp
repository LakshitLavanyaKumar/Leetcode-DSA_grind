class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) return 0;

        vector<int> len(n, 1);  // len[i] = length of LIS ending at i
        vector<int> cnt(n, 1);  // cnt[i] = number of LIS ending at i
        int best = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (len[j] + 1 > len[i]) {
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (len[j] + 1 == len[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            if (len[i] > best) best = len[i];
        }

        long long ans = 0; // safe accumulator
        for (int i = 0; i < n; ++i)
            if (len[i] == best) ans += cnt[i];

        return (int)ans;
    }
};
