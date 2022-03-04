class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> flow(query_row+1, vector<double>(query_row+1,0));
        flow[0][0]=max(0,poured-1);
        for(int i=1;i<=query_row;++i)
        {
            for(int j=0;j<=i;++j)
            {
                double l=0,r=0;
                if(j>0)
                    l=flow[i-1][j-1];
                if(j<i)
                    r=flow[i-1][j];
                if(r+l >=2)
                    flow[i][j]=((r+l)/2)-1;
                if(i==query_row && j==query_glass)
                {
                    if(flow[i][j]!=0)
                        return 1;
                    else
                        return ((r+l)/2);
                }
            }
        }
        return (double)(min(1,poured)); 
        }
};