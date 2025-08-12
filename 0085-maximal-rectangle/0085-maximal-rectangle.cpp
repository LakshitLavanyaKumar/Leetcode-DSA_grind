class Solution {
public:
 vector<int> nextSmallerElement(vector<int> &arr, int size) {
        stack<int> st;
        vector<int> ans(size);
        st.push(-1);

        for (int i = size - 1; i >= 0; i--) {
            while (st.top() != -1 && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.top() == -1 ? size : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> &arr, int size) {
        stack<int> st;
        vector<int> ans(size);
        st.push(-1);

        for (int i = 0; i < size; i++) {
            while (st.top() != -1 && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans =0;
        int m = matrix.size();
        int n  =matrix[0].size();
        vector<int  > h(n,0);
        for(int i =0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j] == '1')
                {h[j]++;}
                else{h[j] =0;}
            }
            int size = h.size();
        vector<int> left = prevSmallerElement(h, size);
        vector<int> right = nextSmallerElement(h, size);

        int maxArea = 0;
        for (int i = 0; i < size; i++) {
            int width = right[i] - left[i] - 1;
            int area = h[i] * width;
            maxArea = max(maxArea, area);
        }
        ans = max(ans , maxArea);
        }
        return ans;
    }
};