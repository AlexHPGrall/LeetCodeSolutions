class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<int>> grid(n, vector<int>(n,0));
        int k=artifacts.size();
        vector<int> dcount(k+1,0);
        int id=1;
       for(vector<int> &v:artifacts)
       {
           int size=0;
           for(int i=v[0]; i<=v[2];++i)
               for(int j=v[1]; j<=v[3];++j)
               {grid[i][j]=id;++size;}
           dcount[id]=size;
           ++id;
       }
        int res=0;
        for(vector<int> &v:dig)
        {
            int i=v[0],j=v[1];
            if(grid[i][j]!=0)
            {
                dcount[grid[i][j]]--;
                if(!dcount[grid[i][j]])
                    res++;
            }
        }
        return res;
    }
};