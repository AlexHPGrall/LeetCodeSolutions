class Solution {
public:
    void Dfs(int curr, int cnt, int n,int k,int i, vector<int>& res)
    {
        //cout<<cnt<<endl;
        curr*=10;
        curr+=i;
        if(cnt == n)
        {res.push_back(curr);return;}
        int j=i-k;
        if(j>=0 && j<=9)
            Dfs(curr, cnt+1, n, k, j, res);
        int l=i+k;
        if(j!=l && l>=0 && l<=9)
            Dfs(curr, cnt+1, n,k,l, res);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        for(int index=1; index<10;++index)
        {
            Dfs(0, 1, n,k,index, res);   
        }
        return res;
    }
};