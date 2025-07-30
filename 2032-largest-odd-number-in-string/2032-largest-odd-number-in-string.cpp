class Solution {
public:
    string largestOddNumber(string num) {
        int n  = num.length();
        string s ="";
        for(int i =n-1;i>=0;i--)
        {
            //cout<<s<<endl;
            if(num[i]=='1' || num[i]=='3' || num[i]=='5'|| num[i]=='7' || num[i]=='9')
            {
                s += num.substr(0,i+1);
                cout<<s<<endl;
                return s;
            }
        }
  
return s;
    }
};