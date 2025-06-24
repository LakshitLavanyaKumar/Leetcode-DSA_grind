class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int f = 0;
        for(int  i =1;i<2006 ;i++)
        { 
             if(binary_search(arr.begin() , arr.end() , i))
             {continue;}
             else{f++;}
            if(f==k)
             {return i;}
        }
        return -1;
    }
};