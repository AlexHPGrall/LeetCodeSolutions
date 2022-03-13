class Solution {
public:
    long long mostPoints(vector<vector<int>>& qu) {
        int n=qu.size();
        vector<long long> pts(n,0);
        pts[n-1]=qu[n-1][0];
        for(int i=n-2; i>=0;--i)
        {
            if(i+qu[i][1]+1>=n)
            {
                pts[i]=max((long long)qu[i][0],pts[i+1]);
            }
            else
            {
                pts[i]=max((long long)qu[i][0]+pts[i+qu[i][1]+1],pts[i+1]);
            }
            //cout<<pts[i]<<endl;
        }
        return pts[0];
    }
};