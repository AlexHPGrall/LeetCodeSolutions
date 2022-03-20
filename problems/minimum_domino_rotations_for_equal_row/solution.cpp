class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        int freq[7]={0};
        int bf[7]={0},tf[7]={0};
        for(int i=0; i<n;++i)
        {
            tf[tops[i]]++;
            bf[bottoms[i]]++;
            freq[tops[i]]++;
            if(tops[i]!=bottoms[i])
                freq[bottoms[i]]++;
        }
        int c1=0, c2=0;
        for(int i=1;i<=6;++i)
        {
            if(freq[i]==n)
            {
                if(c1==0)
                    c1=i;
                else
                    c2=0;
            }
        }
        if(!c1)
            return -1;
        if(c2)
            return 0;
        return min(n-tf[c1],n-bf[c1]);
    }
};
static const auto speedup = []{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();