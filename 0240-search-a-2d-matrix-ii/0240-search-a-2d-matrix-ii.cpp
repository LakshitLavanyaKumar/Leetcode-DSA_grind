class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool p  =false;
        for(int i =0;i<matrix.size();i++)
        {
          //  vector<int> v(matrix[i].begin() , matrix[i].end());
            int j = lower_bound(matrix[i].begin() , matrix[i].end() , target) - matrix[i].begin();
            if(j== matrix[i].size())
            {continue;}
            if(matrix[i][j] == target)
            { p = true;break;}
        }
        return p;
    }
};