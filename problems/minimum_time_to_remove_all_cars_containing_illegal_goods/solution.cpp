class Solution {
public:
    int minimumTime(string s) {
        int best=0, curr=0;
        for(char c:s)
        {
            
            if(c=='1')
                curr++;
            else
                curr--;
            
            if(curr>=0)
                curr=0;
            best=min(best, curr);
                
        }
        return s.size()+best;
    }
};