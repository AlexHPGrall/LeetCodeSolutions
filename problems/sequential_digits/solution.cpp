class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int lc=low,hc=high;
        int lowcount=1, highcount=1;
        while(lc/=10)
            lowcount++;
        while(hc/=10)
            highcount++;
        int dig =lowcount;
        vector<int> res;
        while(dig<=highcount)
        {
            int s=1;
            while(10-s>=dig)
            {
                int curr=0;
                for(int i=0;i<dig;++i)
                    curr=curr*10 +(s+i);
                if(curr>=low && curr<=high)
                    res.push_back(curr);
                s++;
            }
            dig++;
                
        }
        
        return res;
    }
};