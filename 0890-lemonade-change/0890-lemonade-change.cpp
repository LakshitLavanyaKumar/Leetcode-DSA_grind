class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n  = bills.size();
        map<int,int> mp;
        for(int i =0;i<n;i++)
        {
           mp[bills[i]]++;
           if(bills[i] == 10)
           { mp[5]--;}
           if(bills[i] ==20)
           {if(mp[10]>0){mp[10]--;mp[5]--;}
           else{mp[5]--;mp[5]--;mp[5]--;}}

           if(mp[5]<0 || mp[10]<0 || mp[15]<0)
           {return false;}

        }
        return true;
    }
};