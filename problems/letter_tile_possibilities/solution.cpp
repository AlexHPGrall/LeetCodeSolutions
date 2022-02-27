class Solution {
public:
    unordered_set<string> st;
    int n;
    void Dfs(int mask, int count, string &tiles, string &curr)
    {
        if(!curr.empty())
            st.insert(curr);
        if(count == n)
        {
            
            
            return;
        }
        
        for(int i=0; i<n;++i)
        {
            if(mask&(1<<i))
                continue;
            curr.push_back(tiles[i]);
            
            Dfs(mask|(1<<i),count+1,tiles,curr);
            
            curr.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
        n=tiles.size();
        string curr;
        Dfs(0, 0,tiles,curr);
        
        return st.size();
    }
};