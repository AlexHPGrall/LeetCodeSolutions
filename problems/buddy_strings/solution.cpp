class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int diff=0;
        int i=0;
        int n=goal.size();
        int freq[26]={};
        if(s.size()!=n)
            return false;
        bool dup=false;
        while(i<n && s[i] ==goal[i])
        {freq[s[i]-'a']++;if(freq[s[i]-'a']==2)dup=true;++i;}
        if(i==n)
        {
            if(dup)
                return true;
            else
                return false;
        }
        
        char c=s[i];
        int j=i;
        ++i;
        
        while(i<n && s[i] ==goal[i])
            ++i;
        if(i==n)
            return false;
        if(c!=goal[i] || goal[j]!=s[i])
        {
            return false;
        }
        ++i;
        //cout<<"ok"<<i<<endl;
        while(i<n && s[i] ==goal[i])
            ++i;
        if(i!=n)
            return false;
        
        return true;
        
    }
};