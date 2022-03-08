class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,int> candyMap;
        int tcount=0;
        int n=candyType.size();
        for(int n:candyType)
        {
            if(!candyMap.count(n))
                {candyMap[n]++;tcount++;}
        }
        return min(tcount, n/2);
        
    }
};