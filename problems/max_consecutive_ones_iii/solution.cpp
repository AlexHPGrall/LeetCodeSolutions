class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue<int> qu;
        int n = nums.size();
        int res =0, ones=0, cur =0;
       
        for(int i =0; i<n; ++i)
        {
            if(nums[i] ==1)
            {
                cur++;
                ones++;
                
            }
            else{
                if(!k)
                {
                    cur=0;
                }
                else if(qu.size()<k)
                {
                    cur++;
                    qu.push(ones);
                    ones=0;
                }
                else if(qu.size() == k)
                {
                    cur -= qu.front();
                    qu.pop();
                    qu.push(ones);
                    ones=0;
                }
            }
            
            
            res= max(res, cur);
        }
        return res;
    }
};