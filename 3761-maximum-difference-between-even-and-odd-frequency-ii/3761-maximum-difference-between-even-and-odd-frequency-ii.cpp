class Solution {
public:
int getStatus(int a ,int b)
{
    return ((a&1)<<1) | (b&1);
}
    int maxDifference(string s, int k) {
  //sochna yehi tha ki har pair k liye check krnqa hai
  //sliding window hi hai par har pair k l9ye hai ....my constraints are not that big
  int n = s.length();
  int ans = INT_MIN;
   for(char a='0';a<='4';a++)
   {
    for(char b ='0';b<='4';b++)
    {
      int ca = 0;
      int cb =0;
      int pa =0;int pb =0;
      int left =-1;
      vector<int> best(4,INT_MAX);
      for(int right =0;right<n;right++)
      {
        ca+=(s[right] == a);
        cb+=(s[right] == b);
        while(right -left>=k && cb-pb>=2)
        {
            int lefts = getStatus(pa,pb);
            best[lefts] =min(best[lefts ], pa-pb);
            left++;
            pa+=(s[left] == a);
            pb+=(s[left] == b);
        } 
      
      int r = getStatus(ca,cb);
      int req = r^ 0b10;
  if(best[req]!=INT_MAX)
  {
    ans = max(ans, ca-cb-best[req]);
  }
    }
   }
   }
   return ans;
    }
};