class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coord) {
        for(int i=0; i<coord.size()-2;++i)
        {
            int a=coord[i+2][0]-coord[i][0];
            int b=coord[i+2][1]-coord[i][1];
            int c=coord[i+1][0]-coord[i][0];
            int d=coord[i+1][1]-coord[i][1];
            if((a*d) - (b*c))
                return false;
        }
        return true;
    }
};