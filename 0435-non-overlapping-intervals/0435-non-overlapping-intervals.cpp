class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin() , intervals.end());
        int a = intervals[0][0];
        int b = intervals[0][1];
        int c =0;
        for(int i =1;i<n;i++)
        {
         if(intervals[i][0]<b)
         {
            c++;
            b = min(b,intervals[i][1]);
         }
         else{
            b = max(b , intervals[i][1]);
         }
        }
        return c;
    }
};