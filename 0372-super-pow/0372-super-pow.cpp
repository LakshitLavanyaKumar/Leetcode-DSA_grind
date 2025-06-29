class Solution {
public:
long long int power(long long int x,long long int y  , long long  int M)
{
    long long int res =1;
    while(y>0)
    {
        if(y&1)
        {
            res = (res * x)%M;
        }
        x = (x*x)%M;
        y>>=1;

    }
    return res;

}
    int superPow(int a, vector<int>& b) {
       long long int M = 1337;
        long long int r =1;
        for(auto c:b)
        {
            long long h = c ;
         r = (power(r , 10 , M) * power(a,h,M))%M;
        }
        return (int)r;
    }
};