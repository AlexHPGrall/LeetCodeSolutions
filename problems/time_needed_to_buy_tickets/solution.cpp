class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int i=0;
        int res=k+tickets[k];
        int n=tickets.size();
        for(;i<n;++i)
        {
            if(i==k)
                continue;
            if(i<k)
                res+=min(tickets[k],tickets[i])-1;
            else
                res+=min(tickets[k]-1,tickets[i]);

        }
        return res;
    }
};