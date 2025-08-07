class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n  = nums2.size();
        unordered_map<int,int> mp;
        stack<int> st;
        st.push(nums2[0]);
        for(int i =1;i<n;i++)
        {
            int ele = nums2[i];
            if(ele<st.top())
            {st.push(ele);}
            else
            {
                while(!st.empty() && ele>st.top())
                {
                    mp[st.top()] = ele;
                    st.pop();

                }
                st.push(ele);
            } 
        }

        while(!st.empty())
        {
            cout<<st.top()<<endl;
            mp[st.top()] =-1;
            st.pop();
        }
        for(int i =0;i<nums1.size();i++)
        {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};