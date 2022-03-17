class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> st;
        for(int i=0; i<nums.size();++i)
        {
            if(st.empty()||st.back()<nums[i])
                st.push_back(nums[i]);
            else
            {
                int l=0;
                int r=st.size()-1;
                while(l<r)
                {
                    int mid=l+(r-l)/2;
                    //cout<<r<<endl;
                    if(st[mid]<nums[i])
                        l=mid+1;
                    else
                        r=mid;
                }
                
                st[l]=nums[i];
            }
            
        }
        return st.size();
    }
};