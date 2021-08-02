struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

class Solution {
public:
    vector<vector<int>> moves ={{1,0}, {0,1}, {-1, 0}, {0,-1}};
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int res=0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));
        queue<pair<int,int>> q;
        unordered_set<pair<int,int>, pair_hash> st;
        
        for(int i=0; i<n;++i)
            for(int j=0; j<n; ++j)
            {
            
                if(grid[i][j] ==1)
                {
                        int s =0;
                        q.push({i,j});
                        grid[i][j]=-1;
                        while(!q.empty())
                        {
                            int iq = q.front().first, jq = q.front().second;
                            //cout<<iq<<' '<<jq<<endl; 
                            q.pop();
                            ++s;
                            
                            for(int m= 0; m<4; ++m)
                            {
                                int im = iq+moves[m][0], jm=jq+moves[m][1];
                                
                                if(im >=0 && im<n && jm>=0&& jm<n && grid[im][jm] != -1)
                                {
                                    if(grid[im][jm] == 1)
                                    {
                                      q.push({im, jm});  
                                      grid[im][jm]=-1;
                                    }
                                        
                                    else if(grid[im][jm] ==0)
                                        st.insert({im, jm});
                                    
                                   
                                }
                            }
                        }
                        for(auto pa:st)
                        {
                            int is= pa.first, js = pa.second;
                            dp[is][js].push_back(s);
                        }
                        st.clear();
                        res=max(res, s);
                }
            }
        
        for(int i=0; i<n;++i)
            for(int j=0; j<n; ++j)
        {
                int cur =0;
            for(int k : dp[i][j])
                cur +=k;
            res=max(res, cur + 1);
        }
        
        return res;
    }
};