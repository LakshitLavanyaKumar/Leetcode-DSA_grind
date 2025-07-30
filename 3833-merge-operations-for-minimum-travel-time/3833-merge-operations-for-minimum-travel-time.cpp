class Solution {
public:
int N;;
int solve(int i,int k ,int currate,vector<int>& position , vector<int>& time,vector<vector<vector<int>>> &dp){
   if(i == N-1)
   {
    if(k>0){return INT_MAX;}
    return 0;
   }
   if(dp[i][k][currate]!=-1){
    return dp[i][k][currate];
   }
   int result = INT_MAX;
   // no merge
   int skip = solve(i+1,k,time[i+1] , position , time,dp);
   if(skip!=INT_MAX)
   {
   int dist = (position[i+1]-position[i]);
   result = min(result , skip + (dist*currate));
   }
   //we decide to merge
   if(k>0){
    int mergeTime = time[i+1];
    int mergeCount =0;
    for(int j =i+2;j<N && mergeCount<k;j++)
    {
        mergeCount++;
        mergeTime+=time[j];
        int d = solve(j,k-mergeCount,mergeTime,position , time,dp);
if(d!=INT_MAX)
{
        int dist = position[j] - position[i];
        result = min(result , dist*currate   + d);
}
    }
   }
   return dp[i][k][currate] = result;

}

    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
       N =n;
       int h = accumulate(time.begin() , time.end() , 0);
       vector<vector<vector<int>>> dp(n , vector<vector<int>> (k+1 , vector<int> (h+1,-1)));
       return solve(0,k,time[0] , position ,time ,dp);

    }
};