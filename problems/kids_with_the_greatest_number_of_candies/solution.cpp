class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx=0;
        for(int n:candies)
            mx=max(mx,n);
        vector<bool> res;
        for(int n:candies)
        {
            if(n+extraCandies>=mx)
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }
};