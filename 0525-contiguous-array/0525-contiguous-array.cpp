class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n+1,0);
        for(int i =1;i<=n;i++)
        {
            v[i] = v[i-1] + (nums[i-1]==0?1:-1);
        }
        map<int,int> mp;
        int ans =-1;
        for(int  i =0;i<=n;i++)
        {
            if(mp[v[i]]==0 && v[i]!=0)
            {mp[v[i]] = i;}
            else{
                if(v[i]==0)
                {ans = max(ans ,i);}
                else
                {
                ans = max(ans  , i - mp[v[i]]);
            }
            }
        }
        return ans;
    }
};