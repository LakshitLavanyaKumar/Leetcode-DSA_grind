class Solution {
public:
int val =0;
    void f(vector<vector<int>> &ans , int rs ,int re ,int cs,int  ce)
    {
       int size = re-rs;
       if(size ==1)
       {
        ans[rs][cs] = val++;return;
       }
       int mr = rs + size/2;
       int mc = cs + size/2;
        f(ans,rs,mr,mc,ce);
        f(ans,mr,re,mc,ce);
        f(ans,mr,re,cs,mc);
        f(ans,rs,mr,cs,mc);
        //return ;
    }
    vector<vector<int>> specialGrid(int n) {
        if(n==0)
        {return {{0}};}
        int s = 1<<n;
        vector<vector<int>> ans(s , vector<int> (s));
        int l = (s*s)-1;
        // rows,rowe,cols,cole
        f(ans  ,0 , s ,0,s);
      
        return ans;
        
    }
};