class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
       string v  =num;
       sort(v.begin() , v.end());
       stack<char> st;
       if(k==n)
       {
        return "0";
       }
     for(int i=0;i<n;i++)
     {
       while(!st.empty() && k>0 && st.top()>num[i])
       {
         st.pop();k--;
       }
       st.push(num[i]);
     }
     while(!st.empty() && k>0)
     {
        st.pop();k--;
     }
     string h="";
     while(!st.empty())
     {h+=st.top();st.pop();}
     reverse(h.begin() ,h.end());
     int i;
     for(i=0;i<h.size();i++)
     {
        if(h[i]!='0')
        {break;}
     }
        string g = h.substr(i,h.length()-i);
        if(g.length() ==0)
        {return "0";}
        return g;
    }
};