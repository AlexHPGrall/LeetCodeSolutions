class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        unordered_map<string, int>mp;
        for(int i=0; i<logs.size();++i)
        {
            mp[logs[i]]=i;
        }
        sort(logs.begin(), logs.end(), [&mp](string s1,string s2){
            
            int i=0, j=0;
            while(s1[i++]!=' ')
            {}
            while(s2[j++]!=' ')
            {}
            if(s1[i]>='a' && s1[i]<='z')
            {
                if(s2[j]>='a' && s2[j]<='z')
                {
                    while(i<s1.length() && j<s2.length() && s1[i]==s2[j])
                    {
                        ++i;
                        ++j;
                    }
                    if(i==s1.length() && j==s2.length())
                    {
                        i=0;j=0;
                        while(i<s1.length() && j<s2.length() && s1[i]==s2[j])
                    {
                        ++i;
                        ++j;
                    }
                    }
                    if(i==s1.length())
                        return true;
                    if(j==s2.length())
                        return false;
                    return s1[i]<s2[j];
                }
                return true;
            }
            if(s2[j]>='a' && s2[j]<='z')
            {
                return false;
            }
            return mp[s1]<mp[s2];
            
        });
        return logs;
    }
};