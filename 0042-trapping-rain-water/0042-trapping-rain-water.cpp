class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int  waterTrapped =0;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && height[i]>height[st.top()])
            {
                int t = st.top();
                st.pop();
                if(st.size() ==0)
                {break;}
                 int distance = i - st.top() - 1;
            int bounded_height = min(height[i], height[st.top()]) - height[t];
            waterTrapped += distance * bounded_height;
            }
        
        st.push(i);
        }
        return waterTrapped;
    }
};