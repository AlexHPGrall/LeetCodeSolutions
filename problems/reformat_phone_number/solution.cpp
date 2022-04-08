class Solution {
public:
    string reformatNumber(string number) {
        vector<char> nums;
        for(char c:number)
            if(c>='0'&&c<='9')
                nums.push_back(c);
        string res;
        int i;
        int n=nums.size();
        for(i=0; i<n-4;i+=3)
        {
            res.push_back(nums[i]);
            res.push_back(nums[i+1]);
            res.push_back(nums[i+2]);
            res.push_back('-');
        }
        if(n-i==3)
        {
            res.push_back(nums[i]);
            res.push_back(nums[i+1]);
            res.push_back(nums[i+2]);
        }
        else
        {
            res.push_back(nums[i]);
            res.push_back(nums[i+1]);
            i+=2;
            if(i<n)
            {
                res.push_back('-');
                res.push_back(nums[i]);
                res.push_back(nums[i+1]);
            }
        }
        return res;
    }
};