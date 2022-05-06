class Solution {
public:
    int characterReplacement(string s, int k) {
        //vector<int> lastValidIndex(26,0);
        vector<int> charCount(26,0);
        int start=0;
        int currmax=0;
        int res=0;
        for(int i=0; i<s.size();++i)
        {
            charCount[s[i]-'A']++;
            currmax=max(currmax, charCount[s[i]-'A']);
            //cout<<currmax;
            if(1+i-start-currmax<=k)
            {
                res=max(res, 1+i-start);
            }
            else
            {
                charCount[s[start]-'A']-=1;
                start++;
                currmax=*max_element(charCount.begin(), charCount.end());
            }
            
        }
        return res;
    
    }
};