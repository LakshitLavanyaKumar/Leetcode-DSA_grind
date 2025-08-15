class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
       long long int ans =0;
        vector<int> v = cardPoints;
        int n = v.size();
        vector<long long int> pf(n+1,0);
        //pf[0] = v[0];
        for(int i =1;i<=n;i++)
        {
            pf[i] = pf[i-1]+v[i-1];
        }
        for(int i =0;i<=k;i++)
        {
          int p = k-i;
         long long int s =pf[i];
        long long   int ps = pf[n]-pf[n- p];
           long long int b = ps+s;
           ans =max(ans,b);


        }
        return (int )ans;
    }
};