class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int grid[202][202]={0};
        int res=0;
        for(auto &c:circles)
        {
            int x=c[0], y=c[1], r=c[2];
            for(int i=x-r;i<=x+r;++i)
                for(int j=y-r;j<=y+r;++j)
                {
                    if((x-i)*(x-i)+(y-j)*(y-j)<=r*r && grid[i][j]==0)
                    {
                        grid[i][j]=1;
                        res++;
                    }
                }
        }
        return res;
    }
};