class Solution {
    vector<vector<int>> mv={{-1,0}, {0,-1},{1,0},{0,1}};
    vector<vector<pair<int, int>>> parent;
    vector<vector<int>> size;
    pair<int, int> find(pair<int, int> x)
    {
        auto [i, j]=x;
        if(parent[i][j]==x)
            return x;
        parent[i][j]=parent[parent[i][j].first][parent[i][j].second];
        return find(parent[i][j]);
    }
    void merge(pair<int, int> x, pair<int, int> y)
    {
        x=find(x);
        auto [i,j]=x;
        y=find(y);
        auto [k,l]=y;
        if(x==y)
            return;
        if(size[i][j]>=size[k][l])
        {
            parent[k][l]=x;
            size[i][j]+=size[k][l];
        }
        else
        {
            parent[i][j]=y;
            size[k][l]+=size[i][j];
        }
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        if(m==1 && n==1)
            return 0;
            
        parent.resize(m,vector<pair<int, int>>(n));
        size.resize(m, vector<int>(n));
        int r=0;
        int l=INT_MAX;
        for(int i=0; i<m;++i)
            {
                for(int j=0;j<n ;++j)
                {
                    for(auto &mo:mv)
                    {
                        int ni=i+mo[0];
                        int nj=j+mo[1];
                        if(ni>=0 && ni<m && nj>=0 && nj<n)
                        {
                            r=max(r, abs(heights[i][j]-heights[ni][nj]));
                            l=min(l, abs(heights[i][j]-heights[ni][nj]));
                        }
                    }
                }
            }
        
        int k;
        while(l<=r)
        {
            for(int i=0; i<m;++i)
            {
                for(int j=0;j<n ;++j)
                {
                    parent[i][j]={i,j};
                    size[i][j]=1;
                }
            }
            int mid=l+(r-l)/2;
            for(int i=0; i<m;++i)
            {
                for(int j=0;j<n ;++j)
                {
                    for(auto &mo:mv)
                    {
                        int ni=i+mo[0];
                        int nj=j+mo[1];
                        if(ni>=0 && ni<m && nj>=0 && nj<n && abs(heights[i][j]-heights[ni][nj])<=mid)
                            merge({i, j}, {ni, nj});
                    }
                }
            }
            if(find({0,0}) ==find({m-1,n-1}))
            {
                k=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
            
        }
        return k;
    }
};