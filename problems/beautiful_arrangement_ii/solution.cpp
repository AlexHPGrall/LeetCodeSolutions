class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n);
        int l, r;
        l= 1;
        r = n;
        
        for(int i=0 ;i<n; ++i)
        {
            if(i<k)
                res[i]=(i%2==0)?l++:r--;
            else
                res[i] = (k%2==0)?r--:l++;
        }
        
        return res;
    }
};