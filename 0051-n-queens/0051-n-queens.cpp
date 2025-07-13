class Solution {
public:
   void f(int node , vector<bool> &cols, int n,vector<vector<string>> &ans,vector<string> &p)
    {
        if(p.size()==n)
        {ans.push_back(p);
        return;}
      //kisme ni jaa sakta unko nikaaldeta hun baad mai loop to lagana hi hai
      int l = max(node-1, 0);
      int r = min(node+1,n-1);
      int c = node;
      for(int i =0;i<n;i++)
      {
        if(i!=l && i!=c && i!=r && cols[i]==true)
        {
     string s(n,'.');
     cols[i] =false;
            s[i] = 'Q';
           p.push_back(s);
            f(i , cols , n , ans ,p);
            p.pop_back();
            cols[i] =true;
        }
      }
    } 
    vector<vector<string>> solveNQueens(int n) {
        if(n==2 || n==3)
        {return {};}
        vector<bool> cols(n,true);
        vector<vector<string>> ans;
        vector<string> p;
        for(int i =0;i<n;i++)
        {
            cols[i] =false;
            string s(n,'.');
            s[i] = 'Q';
            p.push_back(s);
            f(i , cols , n , ans,p);
            
            cols[i] =true;
        }
        return ans;
    }
};