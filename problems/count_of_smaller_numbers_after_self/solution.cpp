struct mPair
{
  int data;
  int index;
};
class Solution {
public:
    
    vector<int> res;
    void Merge(vector<mPair> &nums, int l, int mid, int r)
    {
        
        int n1 = mid - l +1 , n2 = r-mid;
        vector<mPair> left(n1 +1), right(n2+1);
        for(int h =0; h<n1;++h)
        {
            left[h] = nums[l+h];
        }
        for(int h =0; h<n2;++h)
        {
            right[h] = nums[mid+1+h];
        }
       
        left[n1].data = right[n2].data  = 1e4+1;
        int i= 0, j=0, totCount =0;
         
        for(int k = l; k<=r; ++k)
        {
            if(left[i].data<=right[j].data)
            {
                
                res[left[i].index] += totCount;
                nums[k] = left[i];
                i++;
                
            }
            else
            {
              totCount++;
              nums[k] = right[j];
              j++;  
               
            }
                
        }
    
    }
    void MergeSort(vector<mPair> &nums, int l, int r)
    {
        if(l<r)
        {
            int mid = (l+r)/2;
            MergeSort(nums, l, mid);
            MergeSort(nums, mid+1, r);
           Merge(nums,l,mid,r);
        }
      }
    vector<int> countSmaller(vector<int>& nums) {
        res.resize(nums.size());
        vector<mPair> mNums(nums.size());
       
        for(int i=0; i< nums.size(); ++i)
        {
            res[i] =0;
            mNums[i].data=nums[i];
            mNums[i].index=i;
        }
        
        MergeSort(mNums, 0, nums.size() -1);
        
        
        return res;
        
    }
};