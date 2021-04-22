class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int n = triangle.size() -2; n>=0; --n)
            for(int i=0; i<triangle[n].size(); ++i)
            {
                triangle[n][i] += min(triangle[n+1][i], triangle[n+1][i+1]);
            }
        return triangle[0][0];
    }
};