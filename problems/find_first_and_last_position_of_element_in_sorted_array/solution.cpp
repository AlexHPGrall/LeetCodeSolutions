class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int L=0;
        int R = n;
        int m;
        int right =-1;
        int left = -1;
        int rres, lres;
        vector<int> wrong =vector<int>({-1,-1});
        if(n==0 || nums[0] > target || nums[n-1] < target)
            return wrong;
        if(n==1)
            return vector<int>({0,0});
        while(L<R)
        {
            m=floor((L+R)/2);
            if(nums[m] < target)
            {
                L=m+1;
            }
            else
            {
                if(nums[m]==target && left == -1)
                {
                    left = m;
                    right=R;
                }
                R =m;
            }
        }
        if(nums[L]!=target)
            return wrong;
        lres =L;
        L =left;
        R=right;
        
        while(L<R)
        {
            m=floor((L+R)/2);
            
            if(nums[m] > target)
            {
                R=m;
            }
            else
            {
                L=m+1;
            }
            
           
            
        }
         rres = R-1;
        return vector<int>({lres,rres});
    }
};