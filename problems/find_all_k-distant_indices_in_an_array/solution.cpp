class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        int n=nums.size();
        int p=0;
        for(int i=0; i<n;++i)
        {
            if((nums[i]==key) )
            {
                for(int j=max(p, i-k); j<min(n,i+k+1);++j)
                {
                    res.push_back(j);
                }
                p=min(i+k+1,n);
                
            }
        }
        return res;
    }
};