class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int l=0;
        int r=nums.size();
        vector<pair<int, int>> vec;
        for(int i=0; i<nums.size();++i)
        {
            vec.push_back({nums[i], i});
        }
        
        sort(vec.begin(), vec.end());
        int currmin=INT_MAX;
        int res=0;
        for(auto &[val, index]:vec)
        {
            //cout<<currmin;
            //cout<<val<<' '<<index<<endl;
            if(index>currmin)
                res=max(res, index-currmin);
            currmin=min(index, currmin);
        }
        //cout<<endl;
        return res;
       
    }
};