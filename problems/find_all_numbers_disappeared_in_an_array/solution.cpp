class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        for(int i=0; i<nums.size();++i)
        {
            int j=i;
            while(nums[j]!=0)
            {
                
                int t=nums[j];
                if(nums[t-1] == t)
                {
                    nums[j]=0;
                    nums[t-1]=t;
                    break;
                }
                else
                {
                    swap(nums[j],nums[t-1]);
                }
            }
            
            
        }
        vector<int> res;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==0)
                res.push_back(i+1);
        }
        return res;
    }
};