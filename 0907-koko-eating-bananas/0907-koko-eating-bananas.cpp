class Solution {
public:
bool f(long long int mid ,long long  int h , vector< int> &piles)
{
   long long int s =0;
    for(int i =0;i<piles.size();i++)
    {
       long long   int b = piles[i]%mid==0?piles[i]/mid:piles[i]/mid +1;
        s+=b;
        if(s>h)
        {return false;}
    }
return true;

}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
       long long int l =1;
      long long   int r= accumulate(piles.begin() , piles.end() , 0LL);;
        long long int ans = r;
        while(l<=r)
        { 
long long int mid = (l+r)>>1;
  if(f(mid, h, piles) == true)
  {
    ans = min(ans ,mid);
    r = mid-1;
  }
  else{l = mid+1;}
        }
return (int)ans;
    }
};