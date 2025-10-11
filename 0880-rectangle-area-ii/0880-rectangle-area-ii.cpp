class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        long long int mod = 1e9+7;
        set<long long int> ys;
        for(auto it:rectangles)
        {
            ys.insert(it[1]);
            ys.insert(it[3]);
        }
        sort(rectangles.begin() , rectangles.end());
  long long ans=0;
       long long  int py =*ys.begin();
        for(auto it:ys)
        {
            long long int cy = it;
            long long  height = cy -py;
            if(cy == py)
            {py =it;continue;}
           long long  int xs =-1;
          long long   int xe =-1;
            for(auto it:rectangles)
            {
               long long int x1 = it[0];int y1=it[1];
               long long  int x2 =it[2];int y2=it[3];
                if(y1<= py && y2>= cy)
                {
                    if(x1>xe)
                    {
                        ans = (ans + ((height * ( xe-xs) )%mod ))%mod;
                        xe =x2;
                        xs=x1;
                    }
                    else{
                        xe = max(xe,x2);
                    }
                }
            }
ans = (ans + ((height * ( xe-xs))  %mod))%mod;
py =cy;
        }
        return (int)ans;
    }
};