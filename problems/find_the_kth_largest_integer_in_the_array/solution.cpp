class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(), [](string &a, string &b)
             {
                 if(a.size()<b.size())
                     return true;
                 else if(a.size()>b.size())
                     return false;
                 for(int i=0; i<a.size();++i)
                 {
                     if(a[i]<b[i])
                         return true;
                     if(b[i]<a[i])
                         return false;
                 }
                 return false;
             });

        return nums[nums.size()-k];
    }
};