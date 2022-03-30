class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int x0=points[0][0];
        int x1=points[1][0];
        int x2=points[2][0];
        int y0=points[0][1];
        int y1=points[1][1];
        int y2=points[2][1];
        if((y2-y0)*(x1-x0)!=(y1-y0)*(x2-x0))
        {
            return true;
        }
        return false;
    }
};