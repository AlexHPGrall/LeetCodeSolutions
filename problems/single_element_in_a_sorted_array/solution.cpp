class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l=0, r=n;
        while(l<r)
        {
            int mid = l + (r-l)/2;
           
            if(mid%2)
                mid--;
            if(mid!= n-1 && nums[mid] == nums[mid + 1])
                l = mid + 1;
            else if(mid && nums[mid] == nums[mid -1])
            {
                r = mid;
            }
            else
            {
                return nums[mid];
            }
            
        }
        
        return -1;
    }
};