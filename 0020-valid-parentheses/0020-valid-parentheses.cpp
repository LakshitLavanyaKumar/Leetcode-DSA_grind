class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<int> st;
        for(int  i=0;i<n;i++)
        {
            char ch = s[i];
            if(ch=='(' || ch=='[' || ch=='{')
            {st.push(ch);}
            else 
            {
                if(!st.empty() && ( (st.top() == '(' && ch==')') || (st.top() == '{' && ch=='}') || (st.top() == '[' && ch==']') ) )
                {st.pop();}
                
 
                else 
                {st.push(ch);}
            }
        }
        return st.empty();
    }
};