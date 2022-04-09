class Solution {
public:
    vector<int> dp=vector<int>(1001, -1);
    int dfs(vector<vector<int>> &books, int w, int index)
    {
        
        //cout<<dp[i]<<endl;
        int i=index;
        if(i>=books.size())
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        int currWidth=0;
        int currHeight=0;
        int res=INT_MAX;
        while(i<books.size() && currWidth + books[i][0]<=w)
        {
            
            currHeight=max(currHeight, books[i][1]);
            res=min(res, dfs(books, w,i+1)+currHeight);

            currWidth+=books[i][0];
            ++i;
        }
        dp[index]=res;

        
        //cout<<i<<' '<<res<<' '<<dp[i]<<endl;
        return res;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        return dfs(books, shelfWidth, 0);
    }
};