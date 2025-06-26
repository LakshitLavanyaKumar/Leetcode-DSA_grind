class Solution {
public:
bool f(long long mid ,int n , int a ,int b)
{
    long long p1 = mid/a;
    long long p2 = mid/b;
    long long g = (a*b)/__gcd(a ,b);
    long long p3 = mid/g;
    long long h = p1+p2-p3;
    if(h>=(long long)n){return true;}
    return false;
}
    int nthMagicalNumber(int n, int a, int b) {
       long long  int l = 2;
       long long  int  r = 1e15;
        long long int ans =r;
        while(l<=r)
        {
           long long int mid= (l+r)>>1;
            if(f(mid,n,a,b))
            {
                       ans = min( ans , mid  );
           r = mid-1;
            }
            else{l =mid+1;}
        }
        int M = 1e9+7;
        return ans%M;
    }
};