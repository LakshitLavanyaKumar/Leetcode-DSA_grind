class Solution {
public:
    int divide(int dividend, int divisor) {
      long long   int ans = (long long )dividend/(long long )divisor;
// if(dividend<0LL && divisor<0LL)
// {ans*=(-1LL);} 
cout<<ans<<endl;     
  if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;
        return (int)ans;
    }
};