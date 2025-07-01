class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pf(n+1);
        for(int i =1;i<=n;i++)
        {
            pf[i] = pf[i-1]+((nums[i-1]&1)==1?1:0);
        }
        map<int,int> mp;
        mp[0]=1;
        int ans= 0;
        for(int i =1;i<=n;i++)
        {
           ans+=mp[pf[i] - k];
           mp[pf[i] ]++;
         //  mp[pf[i] - k]++;
        }
return ans;
    }
};