class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
    int n=nums.size();
        int c1,c2;
        int f1=0, f2=0;
        int cnt1=0,cnt2=0;
        c1=c2=0;
        for(int i=0;i<n;++i)
        {
            if(nums[i]==c1)
                ++cnt1;
            else if(nums[i]==c2)
                ++cnt2;
            else if(cnt1==0)
            {cnt1=1;c1=nums[i];}
            else if(cnt2==0)
            {cnt2=1;c2=nums[i];}
            else
            {--cnt1;--cnt2;}
        }

        for(int m:nums)
         {   
            if(m==c1)
                ++f1;
            if(m==c2)
                ++f2;
        }
        if(f1>n/3)
            res.push_back(c1);
        if(f2>n/3 && c2!=c1)
            res.push_back(c2);
        return res;
        
    }
};