class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int in = lower_bound(nums.begin() ,nums.end() , target) -nums.begin();
        cout<<in<<endl;
        return in;

    }
};