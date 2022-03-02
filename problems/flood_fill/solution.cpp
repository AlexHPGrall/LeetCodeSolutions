class Solution {
    const vector<vector<int>> mv={{1,0},{-1,0},{0,1},{0,-1}};
public:
    void Dfs(vector<vector<int>>& image, int sr, int sc, int newColor,int prevColor)
    {
        image[sr][sc]=newColor;
        for(auto v:mv)
        {
            int nr=sr+v[0];
            int nc=sc+v[1];
            if(~nr&& nr<image.size()&& ~nc && nc<image[0].size()&&image[nr][nc]==prevColor)
                Dfs(image,nr,nc,newColor,prevColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int prevColor=image[sr][sc];
        if(prevColor==newColor)
            return image;
        Dfs(image,sr,sc,newColor,prevColor);
        return image;
    }
};