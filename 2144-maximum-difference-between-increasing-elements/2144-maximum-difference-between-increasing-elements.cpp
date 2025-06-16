class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
  int x = nums[0];
  for(int i =1;i<n;i++)
  {
    if(nums[i]>x)
    {
        ans =max(ans , nums[i] - x);
    }
    else{
        x = nums[i];
    }
  }
          return ans;
    }
};