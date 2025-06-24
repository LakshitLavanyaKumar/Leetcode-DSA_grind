class Solution {
public:
bool f(int mid ,int k ,vector<int> &nums)
{
int s =1;
int c =0;
for(int i =0;i<nums.size();i++)
{
    c+=nums[i];
    if(c>mid)
    {
        c = nums[i];
        if(c>mid){return false;}
       s++;
    }
    if(s>k){return false;}

}
return true;
}
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int l =1;
        int r = accumulate(nums.begin() ,nums.end() , 0);
        int ans = r;
        while(l<=r)
        {
            int mid =(l+r)>>1;
            if(f(mid , k ,nums))
            {
                ans =min(ans ,mid);
                r =mid-1;

            }
            else{l = mid+1;}
        }
        return ans;
    }
};