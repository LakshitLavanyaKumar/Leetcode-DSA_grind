class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n  = nums.size();
     sort(nums.begin() , nums.end());
     map<int,int> mp;
     set<int>st;
     for(int i =0;i<n;i++)
     {
        mp[nums[i]]+=nums[i];
        st.insert(nums[i]);
     }   
     vector<int > f(st.begin() , st.end() );
     int n1 = f.size();
          for(auto it:f)
     {cout<<it<<" ";}
     cout<<endl;
     vector<int> dp(n1+2,0);
     for(int i =1;i<=n1;i++)
     {
        //pick
        int notpick = dp[i-1];
        // pick
        int pick = mp[f[i-1]];
        int j =i-1;
        while(j>=1 && (f[j-1]==(f[i-1]-1)))
        {j--;} 
        pick += dp[j];
        dp[i] =max(notpick ,pick); 

     }
     for(int i =0;i<=n1+1;i++)
     {cout<<dp[i]<<" ";}
     cout<<endl;
     return dp[n1];
    }
};