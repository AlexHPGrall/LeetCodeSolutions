class Solution {
public:
    vector<int> distributeCandies(int c, int n) {
        vector<int> res(n);
        int i;
        for(i=1; i<=c;++i)
        {
            res[(i-1)%n]+=i;
            c-=i;
        }
        if(c!=0)
            res[(i-1)%n]+=c;
        return res;
    }
};