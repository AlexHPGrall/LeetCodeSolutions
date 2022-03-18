class Solution {
    int l,r,u,d;
public:
    bool goUp(int i,int j,int n, vector<vector<int>> &res)
    {
        if(res[i][j]==n)
            return false;
        while(i>=u)
        {
            res[i][j]=res[i+1][j]+1;
            //cout<<res[i][j]<<endl;
            if(res[i][j]==n)
            return false;
            --i;
        }
            
        l++;
        return true;
    }
        bool goDown(int i,int j,int n, vector<vector<int>> &res)
    {
        if(res[i][j]==n)
            return false;
            
            //cout<<i<<" "<<j<<endl;
        while(i<=d)
        {
            res[i][j]=res[i-1][j]+1;
            //cout<<res[i][j]<<endl;
            if(res[i][j]==n)
            return false;
            ++i;
        }
        r--;
            return true;
    }
        bool goLeft(int i,int j,int n, vector<vector<int>> &res)
    {
        if(res[i][j]==n)
            return false;
        while(j>=l)
        {
            res[i][j]=res[i][j+1]+1;
            //cout<<res[i][j]<<endl;
            if(res[i][j]==n)
            return false;
            --j;
        }
            
        --d;
            return true;
    }
        bool goRight(int i,int j,int n, vector<vector<int>> &res)
    {
        if(res[i][j]==n)
            return false;
            if(i==0 && j==0)
                ++j;
        while(j<=r)
        {
             res[i][j]=res[i][j-1]+1;
            //cout<<res[i][j]<<endl;
            if(res[i][j]==n)
            return false;
            ++j;
        }
           
        u++;
            return true;
    }
    void printmat(vector<vector<int>> &res)
    {
        for(int i=0; i<res.size();++i)
        {
            for(int j=0; j<res[0].size(); ++j)
                cout<<res[i][j]<<' ';
            cout<<endl;
        }
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        l=0;r=n-1; u=0; d=n-1;
        res[0][0]=1;
        n*=n;
        for(;;)
        {
            if(!goRight(u,l,n,res))
                break;
            //printmat(res);
            //cout<<u<<" ";
            if(!goDown(u,r,n,res))
                break;
            //cout<<r<<" ";
            if(!goLeft(d,r,n,res))
                break;
            //cout<<d<<" ";
            if(!goUp(d,l,n,res))
                break;
            //cout<<l<<endl;
        }
        return res;
        
    }
};