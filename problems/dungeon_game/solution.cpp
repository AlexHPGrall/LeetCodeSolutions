class Solution {
public:
int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m= dungeon.size(), n=dungeon[0].size();
        vector<int> r1(n), r2(n);
        
        r1[n-1] = (dungeon[m-1][n-1]<0)?(-dungeon[m-1][n-1]+1):1;
       
        for(int i=m-1; ~i; --i)
        {
            for(int j =n-1; ~j; --j)
            {
                if(i== m-1 && j == n-1)
                    continue;
                int k;
                if(i==m-1)
                    k=r1[j+1];
                else if(j==n-1)
                    k=r2[j];
                else{
                    if(r2[j]<r1[j+1])
                        k=r2[j];
                    else
                        k=r1[j+1];
                }
                
                
                
                r1[j] = max(k - dungeon[i][j], 1);
            }
            swap(r1,r2);
        }
        
        return r2[0];
    }
};