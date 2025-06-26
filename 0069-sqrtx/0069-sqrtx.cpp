class Solution {
public:
    int mySqrt(int x) {
        if(x==0){return 0;}
       long long  int l = 1;
       long long int r = x;
      long long   int ans =1;
        while(l<=r)
        {
            long long int mid = (l+r)>>1;
            if(mid > x/mid )
            {
                r =mid-1;
            }
            else
            {
                ans =max(mid,ans);
                l =mid+1;
            }
        }
        return (int)ans;
    }
};