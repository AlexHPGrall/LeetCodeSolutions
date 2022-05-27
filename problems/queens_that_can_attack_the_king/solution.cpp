class Solution {
public:
    vector<vector<int>> dirs={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> grid(8,vector<int>(8,0));
        vector<vector<int>> res;
        for(auto &q:queens)
        {
            grid[q[0]][q[1]]=1;
        }
        for(auto &d:dirs)
        {
            int r=king[0], c=king[1];
            while(r>=0 && c>=0 && r<8 && c<8)
            {
                if(grid[r][c]==1)
                {
                    res.push_back({r,c});
                    break;
                }
                r+=d[0];
                c+=d[1];
            }
        }
        return res;
    }
};