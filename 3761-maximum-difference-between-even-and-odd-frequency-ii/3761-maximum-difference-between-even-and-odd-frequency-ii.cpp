class Solution {
public:
int getStatus(int a , int b)
{
    return ((a & 1) << 1) | (b & 1);
}
    int maxDifference(string s, int k) {
        int n  = s.length();
        int ans =INT_MIN;
        for(char a= '0';a<='4';a++)
        {
            for(char b ='0';b<='4';b++)
            {
                int ca =0;
                int cb =0;
                vector<int> best(4,INT_MAX);
                int pa =0;int pb =0;
                int right = 0;
                int left =-1;
                for(int right =0;right<n;right++)
                {
                    ca+=(s[right] == a);
                    cb+=(s[right] == b);
                   while(right -left>=k && cb-pb>=2)
                   {
                        int left_status = getStatus(pa, pb);
                        best[left_status] = min(best[left_status], pa - pb);
                        left++;
                        pa+=(s[left]==a);
                        pb+=(s[left]==b);
                   }
                   int right_status = getStatus(ca, cb);
                    int required_status = right_status ^ 0b10;

                    if (best[required_status] != INT_MAX) {
                        ans = max(ans, ca - cb - best[required_status]);
                    }

                }
            }
        }
        return ans;
    }
};