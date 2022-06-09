class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> og, op;
        for(auto &ope:operations)
        {
            if(og.count(ope[0]))
            {
                op[og[ope[0]]]=ope[1];
                og[ope[1]]=og[ope[0]];
            }
            else
            {
                op[ope[0]]=ope[1];
                og[ope[1]]=ope[0];
            }
        }
        for(int i=0;i<nums.size();++i)
        {
            if(op.count(nums[i]))
                nums[i]=op[nums[i]];
        }
        return nums;
    }
};