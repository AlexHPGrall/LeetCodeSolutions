class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ref[26]={0};
        vector<int> res;
        
        if(s.size()<p.size())
            return res;
        for(char c:p)
        {
            ref[c-'a']++;
        }
        
        int count=0,curr=0;
        for(int i=0;i<s.length();++i)
        {
            int ana[26][2]={0};
            curr=i;
            
            while(i<s.length()&&ref[s[i]-'a'])
            {
                
                if(ana[s[i]-'a'][0]<ref[s[i]-'a'])
                {
                    if(!ana[s[i]-'a'][0])
                        ana[s[i]-'a'][1]=i;
                    ana[s[i]-'a'][0]++;
                    count++;
                }
                else 
                { 
                    i = ana[s[i]-'a'][1];
                    break;
                }
                if(count==p.length())
                {
                    res.push_back(curr);
                    ana[s[curr]-'a'][0]--;
                    ana[s[curr]-'a'][1]=curr+1;
                    curr++;
                    
                    count--;
                    
                }
                  
                
               ++i;     
            }
            //cout<<count<<endl;
            count=0;
        }
        
        return res;
    }
};