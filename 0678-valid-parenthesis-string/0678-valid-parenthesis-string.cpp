class Solution {
public:
    bool checkValidString(string s) {
       int n = s.length();
        int mi =0,ma =0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==')')
            {ma-=1;mi-=1;}
            if(s[i] == '(')
            {ma+=1;mi+=1;}
            if(s[i] == '*')
            {
                mi-=1;
                ma+=1;
            }
            if(mi<0){mi=0;}
            if(ma<0){return false;}
        }
        return mi==0;
    }
};