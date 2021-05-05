class Solution {
public:
    int jump(vector<int>& nums) {
       int n=nums.size();
        int jumps=0, lastjumppos = 0, maxreachable=0;
        int i=0;
        while(lastjumppos < n-1)
        {
            maxreachable = max(maxreachable, nums[i]+i);
            if(i == lastjumppos)
            {
                lastjumppos = maxreachable;
                jumps++;
            }
            
            ++i;
        }
        
        return jumps;
    }
};