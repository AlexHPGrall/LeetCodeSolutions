class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        unordered_map<int, int> mp;
        
        int MaxRes=-1e9;
        
            //cout<<i<<": "<< arr[i]<<endl;
                
                    
        
        
        for(int i:nums)
        {
            mp.insert({i, 1});
        }
        
        for(auto &i:mp)
        {
            int j =0;
            while(mp.find(i.first+(++j)) != mp.end())
            {
                
                i.second += mp[i.first+j];
                mp.erase(i.first+j);
            }
           
            MaxRes=max(MaxRes, i.second);
            
        }
            
        
        return MaxRes;
        
    }
};