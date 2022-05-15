class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int res=0;
        int cur=bottom;
        for(int n:special)
        {
            res=max(res, n-cur);
            cur=n+1;
            //cout<<cur<<endl;
        }
        if(cur<top)
            res=max(res, top-cur+1);
        return res;
    }
};