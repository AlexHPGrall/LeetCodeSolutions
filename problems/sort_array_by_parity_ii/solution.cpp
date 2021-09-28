class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size();
        stack<int> even, odd;
      for(int i=0; i<n; ++i)
      {
          if(i%2 ==0 && nums[i]%2 != 0)
          {
              if(even.empty())
              {
                  odd.push(i);
              }
              else
              {
                  int j=even.top();
                  even.pop();
                  swap(nums[i], nums[j]);
              }
          }
          else if(i%2 ==1 && nums[i]%2 != 1)
          {
              if(odd.empty())
              {
                  even.push(i);
              }
              else
              {
                  int j=odd.top();
                  odd.pop();
                  swap(nums[i], nums[j]);
              }
          }
      }
        return nums;
    }
};