class Solution {
public:
    bool canPlaceFlowers(vector<int>& fbed, int n) {
        int i=0;
        int m=fbed.size();
        if(!n)
            return true;
        while(i<m)
        {
            while(i<m && fbed[i] == 1)
                i+=2;
            if((i<m-1 && fbed[i+1]==0 )|| i==m-1)
            {n--; i+=2;}
            else
                ++i;
            if(n==0)
                return true;
            
            
        }
        
        return (n==0);
    }
};