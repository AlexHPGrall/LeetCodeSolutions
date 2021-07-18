class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        vector<int> ones;
        int n =arr.size();
        for(int i =0; i<n; ++i)
        {
            if(arr[i])
                ones.push_back(i);
        }
        int count = ones.size();
        if(count == 0)
            return {0,2};
        if(count%3 != 0)
            return{-1, -1};
        
        int i = ones[0];
        int j = ones[count/3];
        int k = ones[2*count/3];
        while(k<n && arr[i]==arr[j] && arr[j] == arr[k])
        {
            ++i;++k;++j;
        }
        
        if(k==n)
        {
            return {i-1, j};
        }
        else 
            return {-1,-1};
    }
};