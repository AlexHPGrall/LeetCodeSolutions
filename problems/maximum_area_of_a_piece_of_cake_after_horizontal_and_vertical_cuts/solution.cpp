class Solution {
public:
    int mod =(1e9)+7;
    int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
        int m=hCuts.size();
        int n=vCuts.size();
        sort(begin(hCuts), end(hCuts));
        sort(begin(vCuts), end(vCuts));
        int x= hCuts[0];
        int y=vCuts[0];
        for(int i=1;i<m;++i)
            x=max(x, hCuts[i]-hCuts[i-1]);
        for(int i=1;i<n;++i)
            y=max(y, vCuts[i]-vCuts[i-1]);
        x=max(x, h-hCuts[m-1]);
        y=max(y, w-vCuts[n-1]);
        return (int)((((long long)x%mod)*((long long)y%mod))%mod);
    }
};