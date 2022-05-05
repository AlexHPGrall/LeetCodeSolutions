class Solution {
public:
    int trap(vector<int>& height) {
        int left=0, right =0;
        int i=0, j=height.size()-1;
        int res=0;
        
        left=height[i];
        right=height[j];
        ++i;
        --j;
        while(i<=j)
        {
            if(left <=right)
            {
                res+=max(0, left-height[i]);
                left=max(left, height[i]);
                ++i;
            }
            else 
            {
                res+=max(0,right-height[j]);
                right=max(right, height[j]);
                --j;
            }
        }
        return res;
    }
};