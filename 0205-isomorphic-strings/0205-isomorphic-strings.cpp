class Solution {
public:
    bool isIsomorphic(string s, string t) {
        string p =t;
        map<char,char> mp1,mp2;
        int n = s.length();
      //  cout<<mp['p']<<endl;
        for(int i =0;i<n;i++)
        {
            if(mp1.count(s[i]) && mp1[s[i]]!=p[i])
            {return false;}
            if(mp2.count(p[i]) && mp2[p[i]]!=s[i])
            {return false;}
           mp1[s[i]] = p[i];
           mp2[p[i]] = s[i];
        }
        return true;
    }
};