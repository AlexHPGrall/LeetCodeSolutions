class Solution {
public:
    int maxProduct(vector<int>& nums) {
        queue<int> counts;
        int n=nums.size();
        int res=nums[0];
        if(n==1)
            return res;
        int count =0;
        int prod =1;
        for(int i=0; i<n; ++i)
        {
            prod*=nums[i];
            res=max({prod,nums[i], res});
            //cout<<res<<endl;
            if(nums[i]==0)
            {
                counts.push(count);
                count =0;
                prod=1;
            }
            if(nums[i]<0)
            {
                prod=1;
                count++;
                
            }
        }
        counts.push(count);
        int prod2 =1;
        for(int i =0; i<n; ++i)
        {
            
            count=counts.front();
            counts.pop();
            prod=1;
            prod2=1;
            //cout<<i<<endl;
            if(count%2)
            {
                while(nums[i]>0)
                {
                    prod*=nums[i];
                    ++i;
                }
                prod*=nums[i++];
                
                count--;
                
                while(count>0)
                {
                    
                    if(nums[i]<0)
                    {
                        count--;
                        if(count ==0)
                            break;
                    }
                    prod2*=nums[i];
                    ++i;
                }
                
                res=max(prod*prod2, res);
                
                prod=1;
                
            }
           
            if(i>=n || nums[i] ==0)
                continue;
            
            while(i<n && nums[i] !=0)
            {
                prod*=nums[i];
                ++i;
            }
            
            res=max(prod*prod2, res);
            
            
        }
        
        return res;
    }
};