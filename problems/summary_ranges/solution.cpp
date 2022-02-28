class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
     vector<string> res;
        if(nums.empty())
            return res;
        int a=nums[0],b=nums[0];
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i]!=nums[i-1]+1)
            {
                if(a!=b)
                res.push_back(to_string(a)+"->"+to_string(b));
                else
                    res.push_back(to_string(a));
                a=nums[i];
            }
            
            b=nums[i];
        }
        if(a!=b)
            res.push_back(to_string(a)+"->"+to_string(b));
        else
            res.push_back(to_string(a));
        return res;
    }
};