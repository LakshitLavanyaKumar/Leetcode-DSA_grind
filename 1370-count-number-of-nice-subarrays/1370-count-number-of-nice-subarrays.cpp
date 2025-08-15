class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
        vector<int> pf(n,0);
        if(nums[0]&1){pf[0]=1;}
        else{pf[0] =0;}
        for(int i =1;i<n;i++)
        {pf[i] = pf[i-1]+(nums[i]&1?1:0);}
        mp[0]=1;
        int ans =0;
        for(int i =0;i<n;i++)
        {
            int h = pf[i]-k;
            ans+=mp[h];
            mp[pf[i]]++;
        }
        return ans;
    }
};