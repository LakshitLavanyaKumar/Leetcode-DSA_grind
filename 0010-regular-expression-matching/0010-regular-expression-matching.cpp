class Solution {
public:
   bool f(int i , string &s , int j , string &p)
   {
        if (j < 0) return i < 0;

        if (i < 0) {
            // Remaining pattern must be of form x*x*x*
            if (p[j] == '*' ) return f(i ,s,j-2,p);;;
            return false;
        }
        if(p[j]=='*')
        {
           bool zero = f(i, s,j-2, p);
            // One or more occurrence if match
            bool more = false;
            if (s[i ] == p[j - 1] || p[j - 1] == '.')
                more = f(i - 1,s,j, p);
            return zero || more;
        }
        if(p[j]=='.')
        {return f(i-1,s,j-1,p);}
        if(s[i]==p[j])
        {
        return  f(i-1,s,j-1,p);
        }
        return false;
   }
    bool isMatch(string s, string p) {
        int n1= s.length();
        int n2 = p.length();
        bool k = f(n1-1,s,n2-1,p);
       return k;
    }
};