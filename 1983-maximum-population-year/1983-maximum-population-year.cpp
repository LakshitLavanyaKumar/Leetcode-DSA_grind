class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        //avg diff array behaviour
        vector<int> v(102);
        int n =logs.size();
        for(int i =0;i<n;i++)
        {int a = logs[i][0] -1950;
        int b= logs[i][1] -1950; 
         v[a]+=1; 
         v[b]-=1;

        }
        vector<int > pf(104);
        for(int i = 1;i<=102;i++)
        {
            pf[i] = pf[i-1] + v[i-1]; 
        }
        int k = *max_element(pf.begin()  , pf.end());
        int i ;
        for( i=0;i<=104;i++)
        {
            if(pf[i] == k)
            {break;}
        }
        cout<<i+1949<<endl;
        return (i+1949);
    }
};