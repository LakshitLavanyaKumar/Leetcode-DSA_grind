class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string s2 =to_string(num);
        char c1 =s[0];
        int l =0;
        while(s[l]=='9' && l<s.length() )
        {l++;}
        char c = s[l];
        for(int i =0;i<s.length();i++)
        {
            
        if(s[i] == c)
        {
            s[i]  = '9';
        }
        if(s2[i] == c1)
        {
            s2[i] = '0';
        }
        }
        int a = stoi(s);
        int b =stoi(s2);
        return a-b;
    }
};