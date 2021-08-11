class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n=arr.size();
        map<int,int> mp;
        int count =n;
        for(int i=0;i<n;++i)
        {
            mp[arr[i]]++;
        }
        for(auto it:mp)
        {
            if(it.second>0)
            {
                if(it.first!=0 && mp[it.first*2]>0)
                {
                    int x = min(it.second, mp[2*it.first]);
                    mp[2*it.first] -= x;
                    mp[it.first] -=x;
                    count -= 2*x;
                }
                else if(it.first ==0)
                {
                    count -= it.second;
                    mp[it.first] =0;
                }
            }
        }
        
        return !count;
                            
        
            
        
    }
};