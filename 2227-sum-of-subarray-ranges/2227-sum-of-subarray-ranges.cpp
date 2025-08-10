#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n =nums.size();
        long long int ans =0;
        for(int i =0;i<n;i++)
        {
            long long int a = nums[i];
            long long int b = nums[i];
            for(int j =i+1;j<n;j++)
            {
                  a = max(a  ,(long long)nums[j]);
                  b = min(b , (long long)nums[j]);
                 ans +=(a-b);
            }
        }
        return ans;
    }
};