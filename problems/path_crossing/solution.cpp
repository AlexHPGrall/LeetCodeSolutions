class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0;
        int y=0;
        unordered_map<int, unordered_map<int, int>> pathMap;
        pathMap[0][0]=1;
        for(char c:path)
        {
            if(c=='N')
                ++y;
            if(c=='S')
                --y;
            if(c=='E')
                ++x;
            if(c=='W')
                --x;
            if(pathMap[x][y])
            {
               
                return true;
            }
            pathMap[x][y]=1;
        }
        return false;
    }
};