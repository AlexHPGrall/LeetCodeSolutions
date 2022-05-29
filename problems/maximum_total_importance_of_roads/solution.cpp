class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> roadCount(n,0);
        for(auto &v:roads)
        {
            roadCount[v[0]]++;
            roadCount[v[1]]++;
        }
        multimap<int, int,greater<int>> mmap;
        for(int i=0;i<n;++i)
            mmap.insert({roadCount[i],i});
        long long res=0;
        for(auto &[key, val]:mmap)
        {
            res+=((long long)key*n);
            --n;
        }
        return res;
    }
};