class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {

        int minm=m, minn=n;
        for(auto v:ops)
        {
            minm=min(minm, v[0]);
            minn=min(minn, v[1]);
            
        }
        return minm*minn;
    }
};