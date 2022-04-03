class Solution {
public:
    
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int mx=0;
         for(vector<int> &v:matches)
             mx=max({mx,v[0],v[1]});
    vector<int>  player(mx+1,0); 
        vector<vector<int>> res(2);
        for(vector<int> &v:matches)
        {
            if(player[v[0]]==0)
                player[v[0]]=-1;
            if(player[v[1]] == -1)
                player[v[1]]=0;
            player[v[1]]-=2;
                
        }
        int i=0;
        for(int p:player)
        {
            if(p==-1)
                res[0].push_back(i);
            else if(p==-2)
                res[1].push_back(i);
            ++i;
        }
        return res;
    }
};