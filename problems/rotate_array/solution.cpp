class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n =nums.size();
        vector<int> res(n);
        
        int m=0;
        for(int i=0; i<n-1;++i)
        {
            int index=m;
            for(;;)
            {
                int j=index;
                index =((n-k+index)%n +n)%n;
                if(index==m)
                    break;
                nums[j]=nums[j];
                nums[index]=nums[index];
                swap(nums[j], nums[index]);
                ++i;
            }
            m++;
            /*
            cout<<j<<"->"<<index<<endl;
            for(int k=0;k<n;++k)
                cout<<nums[k]<<" ";
            cout<<endl;
            */
        }
        
    }
};