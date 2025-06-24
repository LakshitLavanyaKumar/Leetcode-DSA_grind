class Solution {
public:
bool f(int mid , int threshold ,vector<int>& nums )
{
  int s =0;
  for(int i =0;i<nums.size();i++)
  {
    int h = nums[i]%mid==0?nums[i]/mid:nums[i]/mid +1;
    s+=h;
    if(s>threshold){return false;}
  }
  return true;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n= nums.size();
        int l = 1;
        int r = *max_element(nums.begin() , nums.end());
        int ans = r;
        while(l<=r)
        {
            int mid = (l+r)>>1;
            if(f(mid, threshold , nums) == true)
            {
                ans = min(ans ,mid);
                r = mid-1;
            }
            else{l = mid+1;}
        }
        return ans;
    }
};