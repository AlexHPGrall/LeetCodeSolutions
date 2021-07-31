class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<3)
            return 0;
        int left =0, right=n-1;
        int maxLeft = height[left], maxRight= height[right];
        int res =0;
        while(left<right)
        {
            if(height[left]<height[right])
            {
                if(maxLeft < height[left])
                    maxLeft=height[left];
                else
                    res+=maxLeft - height[left];
                left++;
            }
            else
            {
                if(maxRight < height[right])
                    maxRight=height[right];
                else
                    res+=maxRight - height[right];
                right--;
            }
        }
        return res;
    }
};