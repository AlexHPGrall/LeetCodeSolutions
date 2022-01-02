class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int freq[60]={0};
        for(int i=0; i<time.size();++i)
        {
            time[i] %=60;
            freq[time[i]] +=1;
        }
        int res=0;
        for(int i=0; i<time.size();++i)
        {
            freq[time[i]]--;
            if(!time[i])
                res += freq[0];
            else
                res +=freq[60-time[i]];
        }
        return res;
    }
};