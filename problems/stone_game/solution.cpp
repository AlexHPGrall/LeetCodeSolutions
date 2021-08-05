class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n=piles.size();
        int Alex=0, Lee =0;
        for(int i=n-1; ~i; --i)
        {
            if(i%2 == 1)
                Alex+=piles[i];
            else
                Lee +=piles[i];
        }
        
        return (Alex > Lee);
    }
};