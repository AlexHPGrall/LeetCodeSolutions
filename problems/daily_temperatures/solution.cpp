class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int> res(n);
        res[n-1] =0;
        
        for(int i=n-2; ~i; --i)
        {
            int j=i+1;
            for(;;)
            {
                if(temp[j]>temp[i])
                {
                    res[i] = j-i;
                    break;
                }
                    
                if(!res[j])
                {
                    res[i] =0;
                    break;
                }
                j+=res[j];
            }
        }
        
        return res;
    }
};