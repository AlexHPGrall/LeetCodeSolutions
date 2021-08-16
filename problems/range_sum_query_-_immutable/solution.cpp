class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int>& nums) {
        sum.push_back(0);
        for(int i=0;i<nums.size(); ++i)
        {
            sum.push_back(nums[i]+sum[i]);
        }
    }
    
    int sumRange(int left, int right) {
        return sum[right+1] - sum[left];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */