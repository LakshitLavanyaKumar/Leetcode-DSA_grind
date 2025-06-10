class Solution {
public:
    int maxDifference(string s) {
        int n =s.length();
        map<int,int> mp;
        for(int i =0;i<n;i++)
        {mp[s[i]]++;}
        int a1 =0;
        int a2 = INT_MAX;
        for(auto it:mp)
        {
            if(it.second%2!=0)
            {
                if(a1<it.second)
                {a1 = it.second;}
            }
            if(it.second%2==0)
            {
                if(a2>it.second)
                {a2 = it.second;}
            }
        }
        int ans =(a2==INT_MAX)?a1:a1-a2;
        return ans;
    }
};