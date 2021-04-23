class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> frq;
        int maxedge=0, width;
        
        for(auto row: wall)
        {
            int indx =0;
            for(int i = 0; i<row.size()-1; ++i)
            {
                
                indx +=row[i];
                frq[indx]+=1;
                maxedge = max(maxedge, frq[indx]);
            }
        }
        return wall.size() - maxedge;
    }
        
};