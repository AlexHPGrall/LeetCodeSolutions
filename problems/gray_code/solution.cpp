class Solution {
public:
    int pow2[17] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768, 65536};
    vector<int> grayCode(int n) {
        if(n==1)
            return {0,1};
        vector<int> res= grayCode(n-1);
        int m=res.size();
        for(int i = m-1; i>=0; --i)
        {
            res.push_back(res[i]|pow2[n-1]);
        }
        return res;
        
    }
};