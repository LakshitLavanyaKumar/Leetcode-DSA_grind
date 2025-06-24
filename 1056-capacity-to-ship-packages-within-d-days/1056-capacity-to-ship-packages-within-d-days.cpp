class Solution {
public:
bool f(int mid ,int days , vector<int>& weights)
{
    int c = 0;
    int d= 1;
    for(int i =0;i<weights.size();i++)
    {
        c+=weights[i];
         if(c>mid){c =weights[i];d++;}
        if(d>days)
        {return false;}
    }
    return true;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int l =*max_element(weights.begin() , weights.end());
        int r = 1e9;
        int ans =r;
        while(l<=r)
        {
            int mid = (l+r)>>1;
            if(f(mid,days , weights))
            {
                ans = min(ans , mid);
                r = mid-1;
            }
            else{l = mid+1;}
        }
        return ans;
    }
};