class Solution {
public:
#define ll long long
    const int MOD = 1000000007;
    int zigZagArrays(int n, int l, int r) {
        ll m   = r-l+1;
       vector<vector<ll>> prev(m+1 , vector<ll>(2)), curr(m+1 , vector<ll>(2));

       for(ll i=1;i<=m;i++)
       {
         prev[i][0] = 1;
         prev[i][1] =1; 
       } 
       for(ll i=2;i<=n;i++)
       {
    
    //       for(ll i=l;i<=r;i++)
    //    {
    //      curr[i][0] = 1;
    //      curr[i][1] =1; 
    //    }
       vector<ll> pref1(m+2,0),pref2(m+2,0);
            for(ll j=1;j<=m;j++)
     {
        pref1[j] = (pref1[j-1]+ prev[j][0])%MOD;
        pref2[j] = (pref2[j-1]+ prev[j][1])%MOD;
     }

     for(ll j =1;j<=m;j++)
     {
        curr[j][1] = pref1[j-1];
        curr[j][0] = ( (pref2[m] - pref2[j]) % MOD + MOD ) % MOD;
     }
        // for(ll j =l;j<=r;j++)
        // {
        //     // pichla bada hai isse.....s=1
        //     for(ll k=l;k<j;k++)
        //     {
        //     dp[i][j][1] = (dp[i][j][1]+dp[i-1][k][0])%MOD; 
        //     }
        //     for(ll k=j+1;k<=r;k++)
        //     {
        //     dp[i][j][0] = (dp[i][j][0]+dp[i-1][k][1])%MOD; 
        //     }
        // }
        swap(prev ,curr);;
        fill(curr.begin(), curr.end(), vector<ll>(2,0));
       }
       ll ans =0;
       for(ll i=1;i<=m;i++)
       {
       //cout<<dp[n][i][0]<<" "<<dp[n][i][1]<<endl;
       ans = (ans+prev[i][0])%MOD;
       ans  = (ans+prev[i][1])%MOD;
       }
       return (int)ans;
    }
};