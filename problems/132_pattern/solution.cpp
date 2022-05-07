class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        vector<int> minIndex(nums.size(),0);
        for(int i=1; i<nums.size();++i)
        {
            if(nums[i-1]<nums[minIndex[i-1]])
                minIndex[i]=i-1;
            else
                minIndex[i]=minIndex[i-1];
            //cout<<minIndex[i]<<endl;
        }
       
        for(int i=0; i<nums.size();++i)
        {
            int n=nums[i];
            while(!st.empty()&&nums[st.top()]<=n)
            {st.pop();}
            
            if(!st.empty())
            {
                int t=nums[st.top()];
                int m=nums[minIndex[st.top()]];
                //cout<<m<<
                if(m<n)
                    return true;
            }
            st.push(i);
            
            
        }
        return false;
    }
};