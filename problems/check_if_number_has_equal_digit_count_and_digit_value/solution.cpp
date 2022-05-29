class Solution {
public:
    bool digitCount(string num) {
        int freq[10]={};
        for(char n:num)
        {
            freq[n-'0']++;
        }
        for(int i=0; i<num.size();++i)
        {
            //cout<<i<<' '<<freq[i]<<' '<<num[i]<<endl;
            if(freq[i]!=(num[i]-'0'))
                return false;
        }
        return true;
    }
};