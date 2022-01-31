class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res=-1;
        for(vector<int> cus:accounts)
        {
            int sum=0;
            for(int n : cus)
                sum+=n;
            res=max(res,sum);
        }
        return res;
            
    }
};