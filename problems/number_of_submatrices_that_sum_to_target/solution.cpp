class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> sum(m+1, vector<int>(n+1,0));
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                sum[i+1][j+1]=matrix[i][j]+sum[i][j+1]+sum[i+1][j]-sum[i][j];
            }
        }
        int res=0;
        for(int r1=0;r1<m;++r1)
        {
            for(int r2=r1;r2<m;++r2)
            {
                unordered_map<int, int> mp;
                mp[0]=1;
                //cout<<r1<<' '<<r2<<':';
                for(int j=0;j<n;++j)
                {
                    
                    int curr=sum[r2+1][j+1]-sum[r1][j+1];
                    //cout<<curr<<", ";
                    if(mp.count(curr-target))
                        res+=mp[curr-target];
                    mp[curr]++;
                }
                //cout<<endl;
            }
        }
        
        return res;
    }
    
};