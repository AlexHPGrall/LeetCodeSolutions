class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length()<k)
            return false;
        vector<int> freq((1<<k),0);
        
        int curr=0;
        int j=0;
        while(j<k)
        {
            curr<<=1;
            if(s[j]=='1')
                ++curr;
            ++j;
            
        }
        //cout<<curr<<endl;
        int cnt=1;
        freq[curr]=1;
        for(; j<s.length();++j)
        {
            curr&=~(1<<(k-1));
            curr<<=1;
            if(s[j]=='1')
                ++curr;
            //cout<<curr<<endl;

            if(freq[curr]==0)
            {
                cnt++;
                freq[curr]=1;
            }
        }
        
        if(cnt==(1<<k))
            return true;
        return false;
           
    }
};