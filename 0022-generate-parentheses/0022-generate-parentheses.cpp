class Solution {
public:
  void f(string &s,int x ,int y, int sum , vector<string>& ans,int n)
  {
    if(sum<0 || (x>n) || (y>n)){return;}
    if(x == n && y==n && sum==0)
    {ans.push_back(s);}
    s.push_back('(');;
    f(s,x+1,y,sum+1,ans,n);
    s.pop_back();
    s.push_back(')');;
    f(s,x,y+1,sum-1,ans,n);
    s.pop_back();
  }
    vector<string> generateParenthesis(int n) {
        //recusion posible
        vector<string> ans;
        string s="(";
  f(s, 1,0,1 ,ans,n);
  return ans;
    }
};