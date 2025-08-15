class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0, n = nums.size();
        int cnt  = 0;
        map<int, int> mp;
        for(int i = 0; i<n; i++) {
            sum += nums[i];

            if(sum == goal) {
                cnt++;
            }

            int rem = sum - goal;

            if(mp.find(rem) != mp.end()) {
                cnt += mp[rem];
            }

            mp[sum]++;
        }
        return cnt;
    }
};