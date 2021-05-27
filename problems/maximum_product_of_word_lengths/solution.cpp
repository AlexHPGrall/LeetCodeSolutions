class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        int n = words.size();
        
        vector<uint32_t> w2i(n);
        for(int i =0; i<n; ++i)
        {
            uint32_t index =0;
            for(char c: words[i])
            {
                index = index | (1<<(c-'a'));
            }
            
            
            w2i[i]=index;
            for(int j=i-1; j>=0; --j)
            {
                if(!(w2i[j]&index))
                    res = max(res, (int)(words[i].size()*words[j].size()));
            }
        }
        
        
       
                
        
        
        return res;
    }
    
};