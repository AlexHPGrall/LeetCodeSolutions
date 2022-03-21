class Solution {
public:
    vector<int> partitionLabels(string s) {
      vector<int> last(26,-1);
        for(int i=0; i<s.length(); ++i)
            last[s[i]-'a']=i;
        int end=last[s[0]-'a'];
        int start=0;
        vector<int> res;
        while(start<s.length())
        {
            for(int i=start; i<=end;++i)
            {
                end=max(end,last[s[i]-'a']);
            }
            res.push_back(end+1-start);
            start=end+1;
            if(start<s.length())
                end=last[s[start]-'a'];
            else
                break;
        }
        return res;
    }
};