class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int i =0;
        int j =n-1;
        sort(people.begin() , people.end()) ;
        int c =0;
        while( i<=j)
        {
            if(people[i]+people[j] <= limit)
            {c++;i++;j--;}
            else{
                j--;c++;
            }
        }
        return c;
    }
};