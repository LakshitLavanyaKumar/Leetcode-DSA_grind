class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> v = asteroids;
    int n = v.size();
    stack<int> st;
    st.push(v[0]);
    for(int i =1;i<n;i++)
    {
        
            st.push(v[i]);
            while(!st.empty())
            {
                int a = st.top();
                st.pop();
                if(st.empty())
                {
                    st.push(a);break;
                }
                if(!st.empty() && ((st.top()<0 && a<0)||(st.top()>0 && a>0 )|| (st.top()<0 && a>0))){st.push(a);break;}
                if(abs(st.top())>abs(a))
                {
                    //st.pop();
                    //continue;
                }
                else if(abs(st.top())<abs(a))
                {
                    st.pop();
                    st.push(a);//continue;
                }
                else if(abs(st.top()) == abs(a)){
                    st.pop();//continue;
                }
                
            
            
            }
    }vector<int> ans;
    while(!st.empty())
    {
      ans.push_back(st.top());
      st.pop();
    }
    reverse(ans.begin() ,ans.end());
    return ans;
    }
};