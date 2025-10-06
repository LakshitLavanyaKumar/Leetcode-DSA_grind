class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
int n = asteroids.size();
stack<int> st;
for(int  i=0;i<n;i++)
{
    int ele = asteroids[i];
    if(!st.empty() && ( (st.top()*ele >0) || (st.top()<0 && ele>0) ))
    {st.push(ele);}
    else{
        while(!st.empty() && st.top()<abs(ele) && st.top()*ele<0)
        {st.pop();}
        if(!st.empty() && st.top()*ele>0)
        {st.push(ele);}
       if(!st.empty() && st.top()*ele<0)
        {if(st.top() == abs(ele)){st.pop();continue;}
         else if(st.top()>abs(ele))
         {continue;}
        }
        else if(st.empty())
        {st.push(ele);}
    }
}
vector<int> ans;
while(!st.empty())
{ans.push_back(st.top());st.pop();}
reverse(ans.begin() , ans.end());
return ans;
    }
};