class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        res[0]=0;
        int i=1;
        while(i<n+1)
        {
            int k=2*i;
            res[i]=1;
            for(int j=i+1;j<n+1&& j<k;++j)
            {
                res[j]=1+res[j-i];
            }
            i=k;
        }
        return res;
    }
};