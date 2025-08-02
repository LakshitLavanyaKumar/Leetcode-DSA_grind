class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n =nums.size();
        int ans =-1e9;
        int s =0;
        for(int i =0;i<n;i++)
        {
           s+=nums[i];
           ans=max(ans,s);
           if(s<0)
           {
           // ans= max(ans,);
            s=0;
           }
           //ans=max(ans,s);
        }
        return ans;
    }
};