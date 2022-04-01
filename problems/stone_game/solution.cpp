class Solution {
public:

    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> arr(n,vector<int>(n,0));
        vector<int> sum(n+1,0);
        for(int i=0; i<n;++i)
            sum[i+1]=sum[i]+piles[i];
            
        for(int sz=1; sz<n;++sz)
        {
                
                for(int i=0, j=sz; j<n;++j, ++i)
                {   
                    if(sz==1)
                        arr[i][j]=max(piles[i],piles[j]);
                    else
                        arr[i][j]=max(piles[i]+(sum[j+1]-sum[i+1])-arr[i+1][j], piles[j]+(sum[j]-sum[i])-arr[i][j-1]);
                }
        }
        //cout<<arr[0][n-1];
        return arr[0][n-1]>sum[n]/2;
    }
};