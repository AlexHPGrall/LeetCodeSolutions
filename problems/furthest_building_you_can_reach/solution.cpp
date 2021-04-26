class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        vector<int> l(ladders);
        int rem, res;
        rem=0;
        int n= heights.size();
        int i=0;
        while(rem<=bricks && i<n-1)
        {
            if(heights[i] >=heights[i+1])
            {
                 ++i;  
                 continue;
            }
                
            if(l.size()<ladders && ladders)
            {
                l.push_back(heights[i] - heights[i+1]);
                if(l.size()==ladders)
                    make_heap(l.begin(), l.end());
            }
            
            else 
            {
                if(ladders && heights[i] - heights[i+1] < l.front() )
                {
                    rem -= l.front();
                    pop_heap(l.begin(), l.end());
                    l.pop_back();
                    l.push_back(heights[i] - heights[i+1]);
                    push_heap(l.begin(), l.end());
                }
                else
                {
                    rem +=heights[i+1] - heights[i];
                }

            }
          if(rem<=bricks)  
            ++i;      
          
            
        }
        return i;
    }
};