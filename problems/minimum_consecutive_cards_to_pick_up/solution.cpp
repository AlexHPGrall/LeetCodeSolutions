class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> freq;
        int res=-1;
        for(int i=0; i<cards.size();++i)
        {
            if(freq.count(cards[i]))
                res=res==-1?i-freq[cards[i]]+1:min(res,i-freq[cards[i]]+1);
            freq[cards[i]]=i;
        }
        return res;
    }
};