class Solution {
public:
    bool sorted = false;
    bool recfind(vector<int>& nums, vector<int> &s, int i, int t)
    {
        for(int j=i; ~j; --j)
        {
            
            if(nums[j] ==t )
            {
                s.push_back(j);
                return true;
            }
            if(nums[j]<t)
            {
                s.push_back(j);
                if(!recfind(nums, s, j-1, t-nums[j]))
                    s.pop_back();
                else
                    return true;
            }
        }
        
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        if(k==1)
            return true;
        int target, sum =0, mx =0;


        if(nums.size() == 0 && k==0)
            return true;
        int n =nums.size();
        if(!sorted)
        {
            sorted= true;
            sort(nums.begin(), nums.end());
        }
            
        
        for(int i:nums)
        {
            //cout<<i<<endl;
           sum += i;
           mx= max(mx, i);
        }
        //cout<<endl;
        target = sum/k;
        if(sum%k != 0 || mx>target)
        {
            //cout<<sum<<endl;
            return false;
        }
            
        if(nums[n-1] == target)
        {
            nums.erase(nums.begin() + n-1);
            return canPartitionKSubsets(nums, k-1);
        }
        int i;
        for(i=n-2;~i; --i)
        {
            if(nums[i] == target-nums[n-1])
            {
                nums.erase(nums.begin() + n-1);
                nums.erase(nums.begin()+i);
                return canPartitionKSubsets(nums, k-1);
                    
            }
            if(nums[i] < target-nums[n-1])
                break;
        }
        vector<int> s;
        recfind(nums, s,i,target-nums[n-1] );
        
        sum=0;
        for(int m:s)
        {
            
            sum+=nums[m];
        }
            
        
        
        if(sum == target-nums[n-1])
        {
            
             nums.erase(nums.begin() + n-1);
            for(int j=0; j<s.size(); ++j)
            {
                
                nums.erase(nums.begin()+s[j]);
                
            }
                
            
            return canPartitionKSubsets(nums, k-1);
                
        }
        
        
        return false;
        
    }
};