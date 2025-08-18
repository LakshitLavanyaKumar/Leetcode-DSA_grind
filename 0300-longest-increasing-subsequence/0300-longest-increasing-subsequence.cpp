class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
//binary search DAMN approach
int n = nums.size();
//vector< int > temp(n ,INT_MIN);
//temp[0] = nums[0];
vector<int> temp;
temp.push_back(nums[0]);
for(int i =1;i<n;i++)
{
    if(nums[i]>temp.back())
    {
        temp.push_back(nums[i]);
    }
    else{
        int in = lower_bound(temp.begin() , temp.end() , nums[i]) - temp.begin();
        temp[in] = nums[i];
    }
}
for(auto it:temp)
{cout<<it<<" ";}
cout<<endl;
return temp.size();
    }
};