class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int i=0;
        vector<int> mem(n,1);
        for(i=1; i<n;++i)
        {
            if(ratings[i]>ratings[i-1])
                mem[i]=mem[i-1]+1;
        }
    
        for(i=n-2; i>=0;--i)
        {
            if(ratings[i]>ratings[i+1])
            {
                if(i>0 && ratings[i]>=ratings[i+1])
                    mem[i]=max(mem[i], mem[i+1]+1);
                else
                    mem[i]=mem[i+1]+1;
            }
           
        }
        
        int res=0;
        for(int num:mem)
            res+=num;
        return res;
    }
};