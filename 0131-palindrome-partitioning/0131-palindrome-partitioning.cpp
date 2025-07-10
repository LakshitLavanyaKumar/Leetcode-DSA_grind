class Solution {
public:
bool ispal(string &x)
{
 int h = x.length();
 for(int i =0;i<(h/2);i++)
 {
    if(x[i] != x[h-i-1])
    {return false;}

 }
 return true;
}
void f(int in,string &a,string s,int n,vector<string> v,vector<vector<string>> &d)
{
   if(in==n)
   {d.push_back(v);return;}
   for(int i = in;i<n;i++)
   {
     a = s.substr(in,i-in+1);
            if(ispal(a))
            {
                v.push_back(a);
                f(i+1 , a ,s,n,v,d);;
                v.pop_back();
            }
   }
}
    vector<vector<string>> partition(string s) {
        vector<string> v;
        int n = s.length();
        string a="";
        vector<vector<string>> d;
        for(int i =0;i<n;i++)
        {
            a = s.substr(0,i+1);
            if(ispal(a))
            {
                v.push_back(a);
                f(i+1 , a ,s,n,v,d);;
                v.pop_back();
            }
        }
        return d;
    }
};