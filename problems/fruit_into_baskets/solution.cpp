class Solution {
public:
    int totalFruit(vector<int>& f) {
        int a=f[0],b=f[0];
        int ai, bi;
        int n=f.size();
        int res=0;
        int curr=0;
        for(int i=0;i<n;++i)
        {
            if(a==b)
            {
                if(f[i]!=a)
                {
                    b=f[i];
                    bi=i;
                }
                else
                {
                    ai=i;
                }
                curr++;
                continue;
                    
            }
            if(f[i]==a)
            {
                ai=i;
                ++curr;
            }
            else if(f[i]==b)
            {
                bi=i;
                ++curr;
            }
            else
            {
                res=max(res, curr);
                if(ai<bi)
                {
                    curr=i-ai;
                    a=f[i];
                    ai=i;
                }
                else
                {
                    curr=i-bi;
                    b=f[i];
                    bi=i;
                }
            }
            
        }
        res=max(curr,res);
            return res;
    }
};