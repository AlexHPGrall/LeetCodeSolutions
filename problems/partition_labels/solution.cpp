class Solution {
public:
    int parent[26];
    //int size[26];
    int find(int x)
    {
        if(x==parent[x])
            return x;
        else
            parent[x]=parent[parent[x]];
        return find(parent[x]);
    }
    int unionf(int x, int y)
    {
        x=parent[x];
        y=parent[y];
        if(x==y)
            return 0;
        else
            parent[y]=x;
        return 1;
    }
    vector<int> partitionLabels(string s) {
        vector<vector<int>> count(26, vector<int>(2,-1));
        int n=s.length();
        for(int i=0; i<n;++i)
        {
            if(count[s[i]-'a'][0]==-1)
                count[s[i]-'a'][0]=i;
            count[s[i]-'a'][1]=i;
        }
        int size[26] ={1};
        
        for(int i=0;i<26;++i)
            parent[i]=i;
        for(int i=0;i<25;++i)
        {
            if(count[i][0]==-1)
                continue;
            for(int j=0;j<26;++j)
            {
                if(i==j || count[j][0]==-1)
                    continue;
                if((count[i][0]<count[j][0] && count[j][0]<count[i][1])||(count[j][0]<count[i][0] && count[i][0]<count[j][1]))
                {
                   if(unionf(i,j))
                   {
                       int start=min(count[i][0], count[j][0]);
                       int end=max(count[i][1], count[j][1]);
                       count[i][0]=start; count[i][1] =end; count[j][0] = start; count[j][1] = end;
                   }
                    
                }
            }
        }
        vector<int> res;
        for(int i=0;i<n;++i)
        {
            //cout<<(char)('a'+i)<<" "<<(char)('a'+find(i))<<endl;
            //cout<<s[i]<<(char)('a'+find(s[i]-'a'))<<endl;
            if(count[s[i]-'a'][0] != -1 &&find(s[i]-'a') == s[i]-'a')
            {
                res.push_back(count[s[i]-'a'][1]-count[s[i]-'a'][0]+1);
                count[s[i]-'a'][0] =-1;
            }
        }
        
        return res;
        
        
    }
};