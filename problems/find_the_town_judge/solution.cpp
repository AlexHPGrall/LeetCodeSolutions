class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusts(n,0), isTrusted(n,0);
        for(auto &p:trust)
        {
            isTrusted[p[1]-1]++;
            trusts[p[0]-1]++;
        }
        for(int i=0; i<n;++i)
        {
            if(isTrusted[i]==n-1 && trusts[i]==0)
                return i+1;
        }
        return -1;
    }
};