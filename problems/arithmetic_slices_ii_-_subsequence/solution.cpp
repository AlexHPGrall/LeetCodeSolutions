#define LL long long
class Solution {
public:
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<LL, int>> count(n);
        LL ans=0;
        
        for(int i=1;i<n;++i)
            for(int j=0; j<i;++j)
            {
                int sum =0;
                LL delta= (LL)nums[i]-nums[j];
                if(count[j].count(delta))
                    sum=count[j][delta];
                count[i][delta]+=sum+1;
                ans+=sum;
            }
        
        return ans;
    }
};