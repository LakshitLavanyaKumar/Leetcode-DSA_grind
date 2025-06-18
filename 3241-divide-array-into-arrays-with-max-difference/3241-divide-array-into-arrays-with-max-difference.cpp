class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<vector<int>> v;
        for(int i =0;i<n;i+=3)
        {
          if(nums[i+2] - nums[i] <=k)
          {
            vector<int> t;
            for(int j =i;j<=i+2;j++)
            {
              t.push_back(nums[j]);
            }
            v.push_back(t);
          }
          else{
            v.clear();return v;
          }
        }
        return v;
    }
};