class Solution {
public:
    int maxScore(vector<int>& vec, int k) {
        int n= vec.size();
        int ans=0;
        for(int i =1; i<n; ++i)
        {
            vec[i] += vec[i-1];
            if(i>= n-k-1)
            {
                if(ans == 0)
                    ans = vec[i];
                else
                    ans = min(ans, vec[i]-vec[i-(n-k)]);
            }
        }
        return (vec[n-1] -ans);
    }
};