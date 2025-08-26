class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans =0;
        int  d =-1;
        int n = dimensions.size();
        for(int i =0;i<n;i++)
        {
            int l =dimensions[i][0];
            int w = dimensions[i][1];

            int g = l*l + w*w;
            if(g>=d)
            {d=g;} 
        }
        for(int i =0;i<n;i++)
        {
              int l =dimensions[i][0];
            int w = dimensions[i][1];

            int g = l*l + w*w;
            if(g==d)
            {ans =max(ans,l*w);} 
        }
        return ans;
    }
};