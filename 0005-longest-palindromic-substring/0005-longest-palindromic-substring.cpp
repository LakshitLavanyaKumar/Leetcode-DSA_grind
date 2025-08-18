class Solution {
public:
    string longestPalindrome(string s) {
         if(s.length()<=1)
         {return s;}
         int n = s.length();
         string fans="";
         for(int i =1;i<n;i++)
         {
            int low = i;
            int high = i;
            while(s[low] == s[high])
            {
                low--;
                high++;
                if(low == -1 || high == n)
                {break;}
            }
            string ans = s.substr(low+1 ,high-low-1 );
           if(ans.length()>fans.length())
           {fans = ans;}

            int l = i-1;
            int h = i;
           
            while(s[l] == s[h])
            {
                l--;
                h++;
                if(l == -1 || h == n)
                {break;}
            }
            string ans1 = s.substr(l+1 ,h-l-1 );
           if(ans1.length()>fans.length())
           {fans = ans1;}
         }
         return fans;
    }
};