class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int i=0;
        int j=piles.size()-1;
        int res=0;
        while(i<j)
        {
            res+=piles[j-1];
            j-=2;
            ++i;
        }
        return res;
    }
};