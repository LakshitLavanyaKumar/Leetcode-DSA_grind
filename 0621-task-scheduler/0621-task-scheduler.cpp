class Solution {
public:

// TC=O(T)--> T=tasks.size()
// SC=O(1)

// Main Logic: We will greedily try to place the char with max freq first.

    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int>freq(26,0);       // O(1) space.

        for(auto it:tasks){           // O(taks.size())
            freq[it-'A']++;
        }

        priority_queue<int>pq;        // max heap.--> O(1) space.

        for(int i=0;i<26;i++){       // O(26)
            if(freq[i]>0)
            pq.push(freq[i]);
        }

        int ans=0;

        while(!pq.empty()){         // O(26)
            int ele=pq.top();
            pq.pop();
            ele--;

            int cnt=0;
            vector<int>temp;
            temp.push_back(ele);
            
// now place 'n' diff elements ahead of current letter.

            while(!pq.empty() && cnt<n){
                
                int val=pq.top();
                pq.pop();
                temp.push_back(val-1);
                cnt++;

            }

            for(auto it:temp){
                if(it>0)
                pq.push(it);
            }

            if(!pq.empty())          // means I would have taken n+1 intervals.
            ans+=n+1;
            else
            ans+=temp.size();
        }

        return ans;


    }
};