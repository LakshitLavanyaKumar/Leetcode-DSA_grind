class Solution {
public:
    int jump(vector<int>& nums) {
      int n = nums.size();
      int l =0;
      int r =0;
      int ans =0;
      while(r<n-1)
      {
       int h =0;  
         for(int i =l;i<=r;i++)
         {
           h = max(h , nums[i]+i);
         }
         l =r+1;;
         r=h;
         ans++;

      }
      return ans;
      
    }
};