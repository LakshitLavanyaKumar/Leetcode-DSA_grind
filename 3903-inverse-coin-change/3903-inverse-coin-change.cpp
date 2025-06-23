class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        vector<int> st;
        int n = numWays.size();
        vector<int> dp(n+1,0);
        dp[0] =1;
        
        for(int  i=0;i<n;i++)
            {
               
                int c =0;
                int ele = i+1;
                for(auto co:st)
                    {
                        if(ele>=co)
                        {
                        c+=dp[ele - co];
                        }
                    }
                int curr = numWays[i] - dp[ele];
                
                if(curr==1 )
                {
                   
                    st.push_back(ele);
                for (int j = ele; j <= n; ++j) {
                    dp[j] += dp[j - ele];
                }
                }
                else if(curr<0 || curr>1){return {};}
            }
        
        return st;
    }
};