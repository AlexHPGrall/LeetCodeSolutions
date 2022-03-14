class Solution {
public:
    vector<vector<int>> mv={{-1,0},{1,0},{0,-1},{0,1}};
    int cutOffTree(vector<vector<int>>& f) {
        int res=0;
        vector<int> h;
        int m=f.size();
        int n=f[0].size();
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
            {
                if(f[i][j]>=2)
                    h.push_back(f[i][j]);
            }
        int si=0, sj=0;
        
        int tot=0;
        sort(h.begin(),h.end());
        if(f[0][0]==h[tot])
            ++tot;
        while(tot<h.size())
        {
            int val=h[tot++];
            queue<pair<int, int>> q;
            q.push({si,sj});
            int dist=0;
            bool found=false;
            vector<vector<int>> vis(m,vector<int>(n,0));
            vis[si][sj]=1;
            while(!q.empty())
            {
                int count=q.size();
                while(count--)
                {
                    int i=q.front().first;
                    int j=q.front().second;
                   
                    q.pop();
                    for(int k=0;k<4;++k)
                    {
                        int ni=i+mv[k][0];
                        int nj=j+mv[k][1];
                        if(ni>=0 && ni<m && nj>=0 &&nj<n&&f[ni][nj]&&!vis[ni][nj])
                        {
                             if(f[ni][nj]==val)
                             {
                                found=true;
                                res+=dist+1;
                                si=ni;
                                sj=nj;
                                goto end;
                             }
                            vis[ni][nj]=1;
                            q.push({ni,nj});    
                        }
                    }

                }

                dist++;   
            }
end: ;
            if(!found)
                return -1;
            
        }
        
        return res;
    }
};