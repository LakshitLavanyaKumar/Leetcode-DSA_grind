class Solution {
public:
    int myAtoi(string s) {
      //pahle number aa gya fir chill hai mamla
      bool fnum =false;
      //fnum will be false only if num ==0
      //iske true ka baad numbers hi aane chahiye aur kuch nhi
      bool fs =false;
      bool fkam = false;
int n=  s.length();
stack<char> st; 
      vector<char> rs;
  for (int i = 0; i < n; i++) {
    if (!fnum) {
        if (s[i] == ' ') continue;
        if (s[i] == '+' || s[i] == '-') {
            fs = true;
            st.push(s[i]);
            fnum = true;
        } else if (isdigit(s[i])) {
            st.push(s[i]);
            fnum = true;
        } else {
            break;
        }
    } else {
        if (isdigit(s[i])) {
            st.push(s[i]);
        } else {
            break;
        }
    }
}
     string d="";
      string h="";
     while(st.size()!=0)
     {
          h = st.top()+h;
          st.pop();
     }
     cout<<h<<endl;
     if(h.size() ==0){return 0;}
     else{
        if(h.size() ==1 && (h[0]=='-' || h[0]=='+'))
        {return 0;}
   
    int i = ( h[0] == '-') ? 1 : 0;
while (i < h.size() && h[i] == '0') i++;
d = h.substr(0,  (h[0] == '-') ? 1 : 0) + h.substr(i);
            cout<<d<<endl;
     }
 int l = d.length();
int start = 0;
int sign = 1;
if (d[0] == '-') {
    sign = -1;
    start = 1;
} else if (d[0] == '+') {
    sign = 1;
    start = 1;
}

long long ri = 0;
for (int i = start; i < l; i++) {
    if (!isdigit(d[i])) break;
    ri = ri * 10 + (d[i] - '0');
    if (sign == 1 && ri > INT_MAX) return INT_MAX;
    if (sign == -1 && ri > 2147483648LL) return INT_MIN; // careful with LL
}

return sign * ri;

      //return 0;
    }
};