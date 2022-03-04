class NumArray {
public:
    int n;
    vector<int> tree;
    NumArray(vector<int>& nums) {
        n=nums.size();
        tree.resize(2*n);
        for(int i=n,j=0; i<2*n;++i,++j)
        {
            tree[i]=nums[j];
        }
        for(int i=n-1; i>0;--i)
        {
            tree[i]=tree[i<<1]+tree[i<<1|1];
        }

        
    }
    
    void update(int index, int val) {
        val-=tree[index+=n];
        while(index)
        {
            tree[index]+=val;
            index>>=1;
        }

    }
    
    int sumRange(int left, int right) {
        int res=0;
        left+=n;
        right+=n;
        while(left<=right)
        {
            //cout<<left<<" "<<right<<endl;
            if(left&1)
            {res+=tree[left++];}
            if(!(right&1))
            {res+=tree[right--];}
            right>>=1;
            left>>=1;
        }

        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */