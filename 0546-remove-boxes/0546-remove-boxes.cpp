class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        static int dp[101][101][101];
        memset(dp,0,sizeof(dp));
        for(int len =1;len<=n;len++)
        {
            for(int i = n-len;i>=0;i--)
            {
                int j = i+len-1;
                for(int k =0;k<=n;k++)
                {
                    int cnt =1;
                    while(i+cnt<=j && boxes[i+cnt] == boxes[i])
                    {cnt++;}
                    int best = (cnt+k)*(cnt+k) + dp[i+cnt][j][0];

                    for(int m =i+cnt;m<=j;m++)
                    {
                        if(boxes[m] == boxes[i])
                        {
                            best = max(best , dp[i+cnt][m-1][0] + (k+cnt<=n?dp[m][j][k+cnt]:0));
                        }
                    }
                    dp[i][j][k] =best;
                }
            }
        }
        return dp[0][n-1][0];
    }
};