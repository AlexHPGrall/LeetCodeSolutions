class Solution {
public:
    int maxLength(vector<string>& arr) {
        uint32_t res =0;
        int n=arr.size();
        vector<int> letters(n,0);
        for(int i=0; i<n; ++i)
        {
            for(char c:arr[i])
            {
                if(!(letters[i]&(1<<c-'a')))
                letters[i]|=(1<<c-'a');
                else
                {
                    letters[i] =-1;
                    break;
                }
            }
        }
        for(uint64_t i =1; i<(1<<n);++i )
        {
            uint32_t mask =0, curr=0;
            for(uint8_t j=0; j<n; ++j)
            {
                if(i&(1<<j))
                {
                    if((letters[j] & mask) || letters[j] == -1)
                       break; 
                    else
                    {
                        mask|=letters[j];
                        curr+=arr[j].size();
                    }
                }
            }
            res = max(res, curr);
        }
        
        return res;
    }
};