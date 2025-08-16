class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n   = cost.size();
        vector<int> dp(n+2 , 0);
        dp[0]=0;
      
        for(int i =3;i<=n+1;i++)
        {
            dp[i] = min(dp[i-2]+cost[i-3] , dp[i-1]+cost[i-2]);
        }
        // 
        return dp[n+1];;
    }
};